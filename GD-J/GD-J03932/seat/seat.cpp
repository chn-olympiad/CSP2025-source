#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[1008],r1,p,d1,d2;
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)
			r1=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r1)
			p=i;
	if(p%n==0)
		d1=p/n;
	else
		d1=p/n+1;
	if(d1%2==1)
		d2=(p%n==0?n:p%n);
	else
		d2=n-p%n+1;
	cout<<d1<<' '<<d2;
	return 0;
}
