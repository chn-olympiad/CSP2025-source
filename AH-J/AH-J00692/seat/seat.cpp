#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==r) k=i;
	int lie=ceil(double(k)/double(n));
	int hang=0;
	int q=k-(lie-1)*n;
	if(lie%2==0) hang=n-q+1;
	else hang=q;
	cout<<lie<<" "<<hang;
	return 0;
}
