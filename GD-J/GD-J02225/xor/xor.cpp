#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=5e5;
int a[maxn+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt1=0,cnt2=0,len,start_pos;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1)
		{
			cnt1++;
			if (a[i-1]==0) start_pos=i;
		}
		else if (a[i]==0&&a[i-1]==1)
		{
			len=i-start_pos;
			if (len%2==0) cnt2+=len/2;
		}
	}
	if (k==1) cout<<cnt1;
	else if (k==0) cout<<n-cnt1+cnt2;
	else cout<<0;
	return 0;
}
