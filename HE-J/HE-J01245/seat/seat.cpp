#include <bits/stdc++.h>
using namespace std;
int n,m,sc,rk,r,c;
int a[105];
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==sc) {
			rk=i;
			break;
		}
	}
	c=(rk+n-1)/n;
	int h=rk%n;
	r=(c%2==0?(n-(h==0?n:h)+1):(h==0?n:h));
	cout<<c<<' '<<r<<endl;
	return 0;
}
