#include <bits/stdc++.h>
using namespace std;
int n,m,exam,l,r,a[105],w,h1,h2;
bool cmp(int a,int b) 
{
	return a>b;
}
int found(int x)
{
	l=1,r=n*m;
	int mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (a[mid]==x) return mid;
		else if (a[mid]>x) l=mid;
		else r=mid;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	exam=a[1];
	sort(a+1,a+n*m+1,cmp);
	w=found(exam);
	if (w%n==0) h1=w/n;
	else h1=w/n+1;
	cout << h1 << " ";
	if (h1%2==1) 
	{
		h2=w%n;
		if (h2==0) h2+=n;
	}
	else h2=n-w%n+1;
	cout << h2;
	return 0;
}
