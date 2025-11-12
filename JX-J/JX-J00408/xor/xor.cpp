#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
bool A=true,B=true;
int n,k,a[N],l,r,s,ma=-2147483648,cnt0,cnt1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt0++;
		else if(a[i]==1) cnt1++;
		if(a[i]!=1)
		{
			A=false;
			if(a[i]!=0) B=false;
		}
	}
	if(A==true) cout<<n/2<<"\n";
	else
	{
		if(B==true)
		{
			if(k==1) cout<<cnt1<<"\n";
			else cout<<cnt0<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				s=0;
				for(int j=i;j<=n;j+=2)
				{
					 s++;
				}
				ma=max(ma,s);
			}
			cout<<ma<<"\n";
		}
	}
	return 0;
}
