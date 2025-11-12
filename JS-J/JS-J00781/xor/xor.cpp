#include<bits/stdc++.h>
using namespace std;
long long n,k,t,ans;
int a[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long l=1,r=1;
	for(int i=1;r<=n;i++)
	{
		t^=a[r];
		if(t==k)
		{
			l=r+1;
			t=0;
			ans++;
		}
		int ll=l,tt=t;
		while(ll<r)
		{
			tt^=a[ll];
			if(tt==k)
			{
				l=r+1;
				t=0;
				ans++;
				break;
			}
			ll++;
		}
		// cout<<r<<" "<<l<<" "<<ans<<'\n';
		r++;
	}
	cout<<ans;
	return 0;
}