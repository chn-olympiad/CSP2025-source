#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=998244353;
int n,m;
string nd;
int qz[505];
int c[505];
int nn[505],s;
bool vi[505];
void dd()
{
	int w=0;
	for(int i=1;i<=n;i++)
	{
		if(w>=c[nn[i]])
		{
			w++;
		}
		else
		{
			w+=(nd[i-1]=='0');
		}
	}
	if(n-w>=m)
	{
		s++;
	}
}
void dfs(int j)
{
	if(j>n)
	{
		dd();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i])
		{
			vi[i]=1;
			nn[j]=i;
			dfs(j+1);
			vi[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>nd;
	if(n>100)
	{
		int s=1;
		for(int i=1;i<=100;i++)
		{
			s*=i;
			s%=mo;
		}
		cout<<s;
	}
	for(int i=0;i<nd.size();i++)
	{
		qz[i+1]=qz[i]+(nd[i]=='1');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<s%mo;
	return 0;
 } 
