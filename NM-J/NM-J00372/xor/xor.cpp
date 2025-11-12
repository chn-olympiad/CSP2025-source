
#include<bits/stdc++.h>
using namespace std;
const int m=5e5+1;
int n,k,a[m];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
	}
	if(n<=2)
	{
		cout<<1;
	}
	cout<<(cnt1/2)+cnt2;
    return 0;
}
