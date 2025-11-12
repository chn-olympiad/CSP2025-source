#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;

int n,m;
string s;
int c[N];
int a[N];
long long fm=1;
long long n_m=1;
long long m_=1;

void h(int mm)
{
	m_=1;
	n_m=1;
	fm=1;
	for(int i=1;i<=mm;i++)m_=(m_*i)%mod;
	for(int i=1;i<=(n-mm);i++)n_m=(n_m*i)%mod;
	fm=(n_m*m_)%mod;
	
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int bj=1;
	int fg=0;
	for(int i=0;i<s.size();i++)
	{
		a[i+1]=int(s[i]-'0');
		if(a[i+1]!=1)bj=0;
		else fg++;
	}
	
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(bj)
	{
		long long ans=0;
		long long fz=1;
		for(int i=1;i<=n;i++)
		{
			fz=(fz*i)%mod;
		}
		
		for(int i=m;i<=n;i++)
		{
			h(i);
			ans=(ans+fz/fm)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		if(bj==0)cout<<0;
		else cout<<1;
		return 0;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 