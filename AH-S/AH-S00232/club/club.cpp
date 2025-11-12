#include<bits/stdc++.h>
using namespace std;
struct p{
	int x,y,z;
}a[100005];
int ans;
int n;
bool cmp(p c,p d){
	return c.x>d.x;
}
void dfs(int now,int sum,int a1,int a2,int a3){
	if(now==n+1){
		//cout<<a1<<" "<<a2<<" "<<a3<<endl;
		ans=max(ans,sum);
		return;
	}
	if(a1<n/2) dfs(now+1,sum+a[now].x,a1+1,a2,a3);
	if(a2<n/2) dfs(now+1,sum+a[now].y,a1,a2+1,a3);
	if(a3<n/2) dfs(now+1,sum+a[now].z,a1,a2,a3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>n;
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0) f1=1;
			if(a[i].z!=0) f2=1;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			ans=0; continue;
		}
		if(!f1&&!f2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			ans=0; continue;
		}
	}
	return 0;
}
