#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int k=a[1],p=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) {
	    if(a[i]==k)	{p=n*m-i+1;break;}
	}
	int c=(p-1)/n+1;
	int r;
	if(c%2==1) r=p-(c-1)*n;
	else r=n-(p-(c-1)*n)+1;
	cout<<c<<" "<<r;
    return 0;	
}
