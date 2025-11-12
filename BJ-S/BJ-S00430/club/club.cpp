#include <bits/stdc++.h>
using namespace std;
struct sb{
	int t1,t2,t3;
}a[100010];
int n,ans=0;
void dfs(int x,int y,int g,int gg,int ggg,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&g<n/2) dfs(x+1,i,g+1,gg,ggg,sum+a[x].t1);
		if(i==2&&gg<n/2) dfs(x+1,i,g,gg+1,ggg,sum+a[x].t2);
		if(i==3&&ggg<n/2) dfs(x+1,i,g,gg,ggg+1,sum+a[x].t3);
	}
}
bool cmp(sb x,sb y){
	if(x.t1==y.t1){
		if(x.t2==y.t2) return x.t3>y.t3;
		return x.t2>y.t2;
	}
	return x.t1>y.t1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].t1>>a[i].t2>>a[i].t3;
		}
		if(n<=20){
			dfs(2,1,1,0,0,a[1].t1);
			dfs(2,2,0,1,0,a[1].t2);
			dfs(2,3,0,0,1,a[1].t3);
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].t1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
