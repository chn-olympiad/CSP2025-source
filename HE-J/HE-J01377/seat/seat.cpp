#include<bits/stdc++.h>
using namespace std;

int n,m,a[114],q,p,r,c;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	q=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[n*m-i+1]==q){
			p=i;
			break;
		}
	}
	r=(p+n)%n;
	if(r==0) c=p/n;
	else c=(p/n)+1;
	if(r==0) r=n;
	if(c%2==1){
		printf("%d %d",c,r);
	}
	else{
		printf("%d %d",c,n-r+1);
	}
	return 0;
}
