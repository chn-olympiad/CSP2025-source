#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum,k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) sum++;
	}
	if(k==1) cout<<sum;
	else cout<<sum/2;
}
