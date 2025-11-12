#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long ans=0;
int a[100005][5];
int cnt[5];
int xiabiao[5],he[5]; 
void dfs(int k,long long sum,int m){
	if(k>=m+1){
		ans=max(ans,sum);
		//cout<<sum<<endl;
		//cout<<"kkk"<<endl;
		return;
	}
	dfs(k+1,sum,m);
	if(a[k][1]!=0 && cnt[1]<m/2){
		cnt[1]++;
		dfs(k+1,sum+a[k][1],m);
		cnt[1]--;
	}
	if(a[k][2]!=0 && cnt[2]<m/2){
		cnt[2]++;
		dfs(k+1,sum+a[k][2],m);
		cnt[2]--;
	}
	if(a[k][3]!=0 && cnt[3]<m/2){
		cnt[3]++;
		dfs(k+1,sum+a[k][3],m);
		cnt[3]--;
	}
}
struct node{
	int x,y,z;
}b[100005];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(he,0,sizeof(he));
		memset(xiabiao,0,sizeof(xiabiao));
		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
				xiabiao[1]++;
				he[1]+=a[i][1];
			}
			if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
				xiabiao[2]++;
				he[2]+=a[i][2];
			}
			if(a[i][3]>a[i][2] && a[i][3]>a[i][1]){
				xiabiao[3]++;
				he[3]+=a[i][3];
			}
			if(a[i][2]!=0 || a[i][3]!=0){
				flag=false;
			}
			b[i]={a[i][1],a[i][2],a[i][3]};
		}
		if(flag){
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i].x;
			}
			printf("%lld\n",ans);
		}
		else if(xiabiao[1]<=n/2 && xiabiao[2]<=n/2 && xiabiao[3]<=n/2){
			printf("%lld\n",he[1]+he[2]+he[3]);
		}
		else{
			dfs(1,0,n);
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
