//GZ-S00119 贵阳市清华中学 喻宥诚 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],mmin=INT_MAX,mmax=INT_MIN;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		mmax=max(w[i],mmax);
		mmin=min(mmin,w[i]);
	}
	cout<<(mmax+mmin)/2;
	return 0;
}
