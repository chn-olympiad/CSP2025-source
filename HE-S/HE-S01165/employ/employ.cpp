#include<bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
int n,m;
string s;
int c[N];
bool en(int n)
{
	int nz=0;
	for(int i=1;i<=n;i++)
	{
		nz++;
	}
	if(nz>c[n]) return false;
	return true;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(en(i)) ans++;;
	}
	cout<<ans;
	return 0;
}
