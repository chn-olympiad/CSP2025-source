#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;typedef int t;typedef long long ll;
t n,m,a[186],selfmk,l,r,mid,sn,sm;
bool cmb(t s,t b){
	return s>b;
}
t main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(t i=1;i<=n*m;i++)scanf("%d",&a[i]);
	selfmk=a[1];
	sort(a+1,a+1+n*m,cmb);
	r=n*m;l=1;
	while(l<r){
		mid=l+r>>1;
		if(selfmk<a[mid])l=mid+1;
		else r=mid-1;
		if(selfmk==a[mid]){
			l=mid;break;
		}
	}
	if(l%n>0)sm=l/n+1;
	else sm=l/n;
	if(sm%2!=0)sn=l-n*(sm-1);
	else sn=n-l+n*(sm-1)+1;
	printf("%d %d",sm,sn);
	return 0;
}
