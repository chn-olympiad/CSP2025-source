#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int g=a[1],k;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==g) {
			k=i;
			break;
		}
	k=n*m-k+1;
	c=(k+n-1)/3;
	int t=(c-1)*n;
	if(c%2!=0) r=k-t;
	else r=n-(k-t)+1;
	cout<<c<<" "<<r;
	return 0;
}