#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int ans;
int n,a[N];
vector<int> v;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i,j,d;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(d=0;d<=(1<<n);d++)
	{
		v.clear();
		for(i=0;i<n;i++) if((d>>i)&1) v.push_back(i+1);
		int sum=0,maxx=0;
		for(int i=0;i<v.size();i++)
		{
			sum+=a[v[i]];
			maxx=max(maxx,a[v[i]]);
		}
		if(v.size()>=3&&(sum>maxx*2))
			ans++;
	}
	cout<<ans;
	return 0;
}
