#include<bits/stdc++.h>
using namespace std;
struct stu{
	int ii,cj;
}a[105];
bool cmd(stu xx,stu yy){
	return xx.cj>yy.cj;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,xzb=0,yzb=0;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;a[i].ii=i;
	}sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++)
		if(a[i].ii==1){ f=i;break; }
	if(f%n!=0)  xzb=f/n+1;
	else  xzb=f/n;
	if(xzb%2!=0)  yzb=(f%n==0)?n:f%n;
	else  yzb=(f%n==0)?1:n-(f%n)+1;
	cout<<xzb<<' '<<yzb;
	return 0;
}
