#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int al[m+10]={0},ar[m+10]={0},mf[m+10]={0},cf[k+10],aaa[n+10];
	for(int i=1;i<=m;i++)
		cin>>al[i]>>ar[i]>>mf[i];
	for(int b=1;b<=k;b++)
	{
	    cin>>cf[b];
		for(int g=1;g<=n;g++) cin>>aaa[g];
	}
	for(int j=1;j<=m;j++)
	    ans+=mf[j];
	cout<<ans<<endl;
	return 0;
}
