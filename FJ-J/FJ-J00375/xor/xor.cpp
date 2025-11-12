#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1000000],sum[1000000],ans=0,l=1,q[100],cnt=0,b,fl;
vector<ll> v[2000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		v[sum[i]].push_back(i);
	}
	for(int r=1;r<=n;r++)
	{
		b=sum[r];
		cnt=0,fl=b^k;
		//cout<<fll<<" "<<fl<<"\n";
		int j=0;
		for(int i=0;i<v[fl].size();i++)
		{
			int p=v[fl][i];
			//cout<<p<<" ";
			if(p<(l-1))
			{
				continue;
			}
			else
			{
				if(p>=r)
				{
					break;
				}
				else
				{
					j=p+1;
					break;
				}
			}
		}
		if(j)
		{
			ans++;
			l=r+1;
			//cout<<j<<" "<<r<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
