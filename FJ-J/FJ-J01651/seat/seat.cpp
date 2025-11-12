#include<bits/stdc++.h>
using namespace std;
bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10001],r,pm,h,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
			pm=i;
	l=ceil(pm*1.0/n);
	pm=pm-(l-1)*n;
	if(l%2==0)
		h=n-pm+1;
	else
		h=pm;
	cout<<l<<" "<<h;
	return 0;
}
