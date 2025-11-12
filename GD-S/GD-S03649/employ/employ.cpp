#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum=0;
bool vis[510];
int num[510];
char s[510];
void dfs(int js,int xx,int ans){
	if(js==n){
		if(ans>=m)sum++;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				if(s[js]=='0'||num[i]<=xx)dfs(js+1,xx+1,ans);
				else dfs(js+1,xx,ans+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	scanf("%d %d %s",&n,&m,&s);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	dfs(0,0,0);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
