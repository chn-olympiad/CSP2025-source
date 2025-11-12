#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[500005],cnt1=0,cnt2;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==k) cnt2++;
	}
	if(k) cout<<cnt;
	else if(!k) cout<<cnt/2;
	else cout<<cnt2;
	return 0;
}
