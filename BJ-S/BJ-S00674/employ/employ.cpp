#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
const int N=505;
vector<int> v,c;
int mul[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=0,cnt2=0;
	ll ans=0;
	string s;
	mul[0]=1;
	for(int i=1;i<=500;i++)
		mul[i]=mul[i-1]*i;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
			v.push_back(cnt);
		else
			cnt++;
	}
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		c.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	sort(c.begin(),c.end());
	for(int i=0;i<(1<<v.size());i++)
	{
		int cpi=i,cnt3=0;
		while(cpi)
		{
			if(cpi&1)
				cnt3++;
			cpi>>=1;
		}
		if(cnt3<m)
			continue;
		cpi=i;
		ll sum=1;
		int cnt4=0;
		for(int j=0;j<v.size();j++)
		{
			if(cpi&1)
			{
				ll x=upper_bound(c.begin(),c.end(),v[j])-c.begin();
				x=n-x-cnt4;
				sum*=x;
				sum%=Mod;
				cnt4++;
			}
			cpi>>=1;
		}
		cpi=i;
		for(int j=0;j<v.size();j++)
		{
			if(!(cpi&1))
			{
				ll x=upper_bound(c.begin(),c.end(),v[j])-c.begin();
				sum*=x;
				sum%=Mod;
			}
			cpi>>=1;
		}
		sum*=mul[n-v.size()];
		sum%=Mod;
		ans+=sum;
		ans%=Mod;
	}
	cout<<ans<<'\n';
	/*if(cnt==0)
	{
		ll sum=1;
		for(int i=1;i<=n-cnt2;i++)
		{
			sum*=(ll)i;
			sum%=Mod;
		}
		cout<<sum<<'\n';
		return 0;
	}*/
	return 0;
}