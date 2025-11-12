#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum,s[500010],sp;
typedef pair<long long,long long> pll;
vector<pll> ps;
vector<long long> ps2;
bool cmp(pll pl1,pll pl2)
{
	return pl1.first<pl2.first;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum^=a[i];
		s[i]=sum;
	}
	//l~r异或和：s[r]^s[l-1]
	//s[r]^s[l-1]==k
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				ps.push_back({i,j});
			}
		}
	}
	sort(ps.begin(),ps.end(),cmp);
	long long p=0;
	vector<long long> k,ev;
	for(long long i=0;i<ps.size();i++)
	{
		ps2.push_back(0);
		if(ps[i].first>p)
		{
			k=ev;
			k.push_back(i);
			p=ps[i].first;
		}
		else if(ps[i].second==p)
		{
			k.push_back(i);
			for(long long j=0;j<k.size();j++)
			{
				ps2[k[j]]++;
			}
			ps2[i]++;
		}
		else
		{
			for(long long j=0;j<k.size();j++)
			{
				ps2[k[j]]++;
			}
			ps2[i]++;
		}
	}
	long long maxp=0;
	for(long long i=0;i<ps2.size();i++)
	{maxp=max(maxp,ps2[i]);sp+=ps2[i];}
	while(sp!=0)
	{
		for(long k2=ps.size()-1;k2>=0;k2--)
		{
			if(maxp==ps2[k2])
			{
				ps.erase(ps.begin()+k2);
				maxp=0;
				sp=0;
				ps2=k=ev;
				for(long long i=0;i<ps.size();i++)
				{
					ps2.push_back(0);
					if(ps[i].first>p)
					{
						k=ev;
						k.push_back(i);
						p=ps[i].first;
					}
					else if(ps[i].second==p)
					{
						k.push_back(i);
						for(long long j=0;j<k.size();j++)
						{
							ps2[k[j]]++;
						}
						ps2[i]++;
					}
					else
					{
						for(long long j=0;j<k.size();j++)
						{
							ps2[k[j]]++;
						}
						ps2[i]++;
					}
				}
				for(long long i=0;i<ps2.size();i++)
				{maxp=max(maxp,ps2[i]);sp+=ps2[i];}
			}
		}
	}
	cout<<ps.size();
}
