#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct str{
	string start,end;
};
ll q,n,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	str zfq[n];
	str wt[q];
	for(ll i=0;i<n;i++)
	{
		cin>>zfq[i].start>>zfq[i].end;
	}
	for(ll i=0;i<q;i++)
	{
		cin>>wt[i].start>>wt[i].end;
	}
	string x,y,z;
	for(ll i=0;i<q;i++)
	{
		y=zfq[i].start;
		if(y==wt[i].end)
		{
			ans++;
		}
		else
		{
			for(ll j=0;j<n;j++)
			{
				x=zfq[j].start;
				for(ll k=0;k<n;k++)
				{
					z=zfq[k].start;
					if(x+y+z==wt[i].end)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0; 
}
