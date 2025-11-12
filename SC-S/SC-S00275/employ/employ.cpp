#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[510],c[510],b[510],vis[510];
void dfs(int j)
{
	if(j>n){
		int sum=0,res=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=b[c[i]]){
				sum++;
			}
			else 
			{
				if(a[i]==0){
					sum++;
				}
				else{
					res++;
				}
			}
		}
		//cout<<res<<endl;
		if(res>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;c[j]=i;
		dfs(j+1);
		vis[i]=0;c[j]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		a[i]=x-'0';
	}
	for(int j=1;j<=n;j++){
		cin>>b[j];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 