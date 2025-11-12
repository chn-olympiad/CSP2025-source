#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=2e5+5,Mod=127,Mod2=998244353;
ull s[N][5],t[N][5];
ll ans=0;
vector<pair<ull,pair<int,int> > > v;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		s[i][1]=s[i][2]=0;
		for(int j=0;j<s1.length();j++)
		{
			s[i][1]=s[i][1]*Mod+s1[j];
			s[i][2]=s[i][2]*Mod+s2[j];
		}
		v.push_back({s[i][1]-s[i][2],{s1.length(),s1[s1.length()-1]}});
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>s1>>s2;
		t[i][1]=t[i][2]=0;
		int flag=0;
		for(int j=s1.length()-1;j>=0;j--)
		{
			if(s1[j]!=s2[j])
			{
				flag=j;
				break;
			}
		}
		for(int j=0;j<s1.length();j++)
		{
			t[i][1]=t[i][1]*Mod+s1[j];
			t[i][2]=t[i][2]*Mod+s2[j];
			if(j>=flag)
			{
				pair<ull,pair<int,int> >mt={t[i][1]-t[i][2],{0,0}};
				int nx=lower_bound(v.begin(),v.end(),mt)-v.begin();
				for(int i=nx;i<v.size();i++)
				{
					if(v[i].first!=mt.first)
						break;
					if(j+1>=v[i].second.first&&v[i].second.second==s1[j])
						ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}