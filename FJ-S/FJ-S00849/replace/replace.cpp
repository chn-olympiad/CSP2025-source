#include<bits/stdc++.h>
#define ll long long
const int HM=344515343;
const int HB=131;
const int HI=999997;
using namespace std;
ll geth(string s)
{
	ll res=0;
	for(int i=0;i<s.size();i++)
	{
		res=(res*HB+s[i])%HM;
	}
	return res;
}
vector<int>ht[HI];
void insert(ll x)
{
	ht[x%HI].push_back(x);
}
int find(ll x)
{
	int sum=0;
	if(ht[x%HI].empty())
	{
		return 0;
	}
//	cout<<"___"<<x<<'\n';
	for(int i=0;i<ht[x%HI].size();i++)
	{
		if(ht[x%HI][i]==x)
		{
			sum++;
		}
	}
	return sum;
}
ll abh[5000001][2],pwr[5000001];
ll subh(int l,int r,int op)
{
	if(l==0)
	{
		return abh[r][op];
	}
	return (abh[r][op]-abh[l-1][op]*pwr[r-l+1]%HM+HM+HM)%HM;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string sa,sb;
		cin>>sa>>sb;
		insert(geth(sa+sb));
//		cout<<geth(sa+sb)<<'\n';
	}
	pwr[0]=1;
	for(int i=1;i<=5000000;i++)
	{
		pwr[i]=pwr[i-1]*HB%HM;
	}
	while(q--)
	{
		string sa,sb;
		cin>>sa>>sb;
//		cout<<geth(sa+sb)<<'\n';
		int len=sa.size(),ans=0;
		for(int i=0;i<len;i++)
		{
			abh[i][0]=(abh[i-1][0]*HB+sa[i])%HM;
		}
		for(int i=0;i<len;i++)
		{
			abh[i][1]=(abh[i-1][1]*HB+sb[i])%HM;
		}
//		cout<<geth("xabcx")<<' '<<subh(0,4,0)<<' '<<abh[4][0]<<'\n';
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
//				cout<<subh(i,j,1)*pwr[j-i+1]<<'\n';
//				cout<<i<<' '<<j<<' '<< (subh(i,j,0)*pwr[j-i+1]%HM+subh(i,j,1))%HM<<'\n';
				ans+=find((subh(i,j,0)*pwr[j-i+1]%HM+subh(i,j,1))%HM)*(abh[i-1][0]==abh[i-1][1]&&subh(j+1,len-1,0)==subh(j+1,len-1,1));
			}
		}
		cout<<ans<<'\n';
	}
}
