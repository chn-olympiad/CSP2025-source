#include <bits/stdc++.h>
using namespace std;
priority_queue<int> que;
int T,n,ans,x,y,z,a[250],b[250],c[250];
void dfs(int k,int x,int y,int z,int cnt){
	if(k>=n){
		ans=max(ans,cnt);
		return;
	}
	if(x+1<=n/2) dfs(k+1,x+1,y,z,cnt+a[k]);
	if(y+1<=n/2) dfs(k+1,x,y+1,z,cnt+b[k]);
	if(z+1<=n/2) dfs(k+1,x,y,z+1,cnt+c[k]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=200){
			ans=0;
			for(int i=0;i<n;i++)
				cin>>a[i]>>b[i]>>c[i];
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}else{
			ans=0;
			for(int i=0;i<n;i++){
				cin>>x>>y>>z;
				que.push(x);
			}
			for(int i=0;i<n/2;i++){
				ans=ans+que.top();
				que.pop();				
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
