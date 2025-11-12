#include<iostream>
#include<algorithm>
#define int unsigned
using namespace std;
signed main(){
int n,x,y,i,j,*a,kv,idx,ax,ay;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	n=x*y+1;
	a=new int[n];
	for(i=1;i<n;++i)cin>>a[i];
	kv=a[1];
	sort(a+1,a+n);
	for(i=1;i<n;++i)
	 if(a[i]==kv){
	  idx=n-i;
	  break;
	 }
	ax=idx%x+1;
	ay=floor(idx/x);
	if(ax==1||ax==x)++ay;
	if(idx%x==0)--ay;
	if(ay%2)ax=x-ax+1;
	cout<<ay<<' '<<ax;
	return 0;
}
