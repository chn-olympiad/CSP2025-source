#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
unordered_map<int,vector<int> > mp;
int a[500010],h[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[i]=h[i-1]^a[i];
		mp[h[i]].push_back(i);
	}
	int r=0;
	for(int i=1;i<=n;i++)
	{
		int awa=k^h[i-1];
//		cout<<i<<"\n----------\n";
		if(mp[awa].size()==0)
			continue;
		int ll=0,rr=mp[awa].size()-1;
		while(ll<rr)
		{
			int mid=(ll+rr)>>1;
			if(mp[awa][mid]<i)
				ll=mid+1;
			else
				rr=mid;
		}
//		cout<<awa<<" "<<mp[awa][ll]<<"\n";
		int w=mp[awa][ll];
		if(w<i)
			continue;
		if(i>r)
		{
			r=w;
			ans++;
		}
		else if(w<r)
			r=w;
	}
	cout<<ans<<"\n";
	return 0;
}