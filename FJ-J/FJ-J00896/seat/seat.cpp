#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,a[1005];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++) cin>>a[i];
	int r=a[1],id=0;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++) 
	{
		if(a[i]==r)
		{
			id=i;
			break;
		}
	}
	int l=id/n,y=id%n;
	if(y==0)
	{
		if(l%2==0) cout<<l<<" "<<1;
		else cout<<l<<" "<<n;
	}
	else
	{
		cout<<l+1<<" ";
		if((l+1)%2==1) cout<<y;
		else cout<<n-y+1;
	}
	return 0;
} 
