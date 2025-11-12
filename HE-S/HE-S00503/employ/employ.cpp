#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=505;
string s;
int c[N],a[N];
bool op=false;
long long ans;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			op=true;
		}
		a[i+1]=s[i]-'0';
	}
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
	
	return 0;
}
