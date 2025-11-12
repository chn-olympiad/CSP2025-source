#include<bits/stdc++.h>
using namespace std;
#define mod 998224353
const int N=1e6+10;
int c[N];
long long ax(long long n)
{
	long long res=1;
	while(n>=2)
	{
		res*=n;
		n--;
		res%=mod;
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long res=0;
	for(int i=m;i<=n;i++)
	{
		res+=ax(i);
		res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}
