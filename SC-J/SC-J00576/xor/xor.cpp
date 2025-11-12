#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k,z=0; cin>>n>>k;
	vector<int> a(n);
	vector<int> v(n,1000000000);
	for(auto &x:a) cin>>x;
	for(int x=0,y=0;x<n;x++)
	{
		int lz=0;
		for(y=x;y<n;y++)
		{
			lz^=a[y];
			if(lz==k)
			{
				v[x]=y;
				break;
			}
		}
	}
	for(int x=0,y=0;x<n;x++)
	{
		int lz=1000000000;
		for(y=x;y<n;y++)
			lz=min(lz,v[y]);
		if(lz!=1000000000) x=lz,z++;
	}
	cout<<z;
	return 0;
}