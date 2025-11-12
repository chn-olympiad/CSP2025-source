#include<bits/stdc++.h>
using namespace std;
int a[105];
#define int long long
bool cmp(int n,int m){
	return n>m;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	int xiaor;
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if(i==1) xiaor=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int pmxr;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaor){
			pmxr=i;
			break;
		}
	}
	int asdfg=2*n,xrdz;
	xrdz=(pmxr-1)/asdfg;
	int xrbzpm;
	xrbzpm=pmxr-xrdz*asdfg;
	int xrdh,xrdl; 
	if(xrbzpm<=n){
		xrdl=2*xrdz+1;
		xrdh=xrbzpm;
	} 
	if(xrbzpm>n){
		xrdl=2*xrdz+2;
		xrdh=n-(xrbzpm-n-1);
	}
	printf("%lld %lld",xrdl,xrdh);
	return 0;
} 
