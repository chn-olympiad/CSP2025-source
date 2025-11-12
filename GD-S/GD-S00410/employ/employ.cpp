#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int c[105];
char s[105];
bool flag[105];
void dfs(int id,int rf)
{
	if(id==n+1)
	{
		if(n-rf>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			if(rf>=c[i]||s[id]=='0') dfs(id+1,rf+1);
			else dfs(id+1,rf);
			flag[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]; 
	}
	dfs(1,0);
	cout<<ans;
}
/*
mi huo xing wei da shang
luogu:shuaiqbr

wo mei huo le
*/
