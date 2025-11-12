#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int a[N],sum=0;
bool cmp(int a,int b){
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=1,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>=sum&&l%2==1)
		{
			r++;
		}
		if(a[i]>=sum&&l%2==0)
		{
			r--;
		}
		if(r>m)
		{
			r=m;
			l++;
		}
		if(r<1)
		{
			r=1;
			l++;
		}
		if(a[i]==sum)
		{
			cout<<l<<" "<<r;
			return 0;
		}
	}
	return 0;
}
