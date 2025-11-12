#include<bits/stdc++.h>
using namespace std;
#define N 110

int n,m,a[N];
bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
//	freopen("seat3.in","r",stdin);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int l=1,r=n*m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=x)l=mid+1;
		else r=mid-1;
	}
//	cout<<r<<'\n';
	int lie=r/n+1;
	r=r%n;
	if(r==0)r=n,lie--;
	int hang=0;
	if(lie&1)hang=r;
	else hang=m-r+1;
	cout<<lie<<' '<<hang<<'\n';
	
	
	
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/
