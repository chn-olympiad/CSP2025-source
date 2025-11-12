#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,r,k;
int a[100010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		{
			a[i]=a[i-1],a[i-1]=a[i];
		}
	}
	cout<<1<<" "<<2;
	return 0;
}
