#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=1e9+7;
#define ll long long
int n,s[N],a[N],m,c[N];
ll ans;
bool ff;
char ss[N];
void dfs(int p)
{
	if(p>n)
	{
		int x=0,k=0,p=0;
		for(int i=1;i<=n;i++)
		 if(x>=c[i]) x++;
		 else
		 {
		 	p++;
		 	if(s[p]) k++;
		 	else x++;
		 }
		if(k>=m)
		 ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	 if(!c[i])
	 {
	 	c[i]=a[p];
	 	dfs(p+1);
	 	c[i]=0;
	 }
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>ss+1;
	for(int i=1;i<=n;i++)
	 if(ss[i]=='1') s[i]=1;
	 else s[i]=0,ff=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(!ff&&n>18)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		 if(a[i]) k++;
		if(k>=m) ans=1;
		for(int i=1;i<=n;i++)
		 ans=ans*i%mod;
		cout<<ans;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
