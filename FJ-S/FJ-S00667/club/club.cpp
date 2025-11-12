#include<bits/stdc++.h>
using namespace std;
int t,n,v[4],ans;
int cnt,l[114514];
struct Grizeman{
	int x,y,z;
}k[1919810],a[100001];
bool vis[100001],v1,v2;
bool cmp(Grizeman a,Grizeman b){
	return a.x>b.x;
}
void dfs(int x,int y){
	if(x==n+1){
		ans=max(y,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(v[i]<n/2){
			v[i]++;
			dfs(x+1,y+((i==1)?a[x].x:((i==2)?a[x].y:a[x].z)));
			v[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=v1=v2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0||a[i].z!=0)v1=1;
			if(a[i].z!=0)v2=1;
		}
		v[1]=v[2]=v[3]=0;
		if(!v1){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
		}
		else if(!v2){
			dfs(1,0);
		}
		else{
			dfs(1,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//			if(a[i].x>a[i].y){
//				if(a[i].y>a[i].z){
//					l[i]=a[i].y;
//				}
//				else if(a[i].z>a[i].x){
//					l[i]=a[i].x;
//				}
//				else l[i]=a[i].z;
//			}
//			else{
//				if(a[i].z<a[i].y)
//					l[i]=a[i].y;
//				else if(a[i].z>a[i].x)
//					l[i]=a[i].x;
//				else l[i]=a[i].z;
//			}
//			k[++cnt]={a[i].x,i,1};
//			k[++cnt]={a[i].y,i,2};
//			k[++cnt]={a[i].z,i,3};
//			vis[i]=0;
//		}
//		v[1]=v[2]=v[3]=0;
//		sort(k+1,k+1+cnt,cmp);
//		for(int i=1;i<=cnt;i++){
//			if(!vis[k[i].y]&&v[k[i].z]<n/2){
////				cout<<v[k[i].z];
//				v[k[i].z]++;
//				vis[k[i].y]=1;
//				ans+=k[i].x+l[k[i].y];
//			}
//		}
