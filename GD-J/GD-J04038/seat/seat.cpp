#include<bits/stdc++.h>
using namespace std;
int m,n,p=0,r1,c,r,r2;

int a[10000];
bool cmp(int h,int g){
	return h>g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		p++;
		cin>>a[p];
	}
	r2=a[1];
	sort(a+1,a+m*n+1,cmp);
	p=0;
	for(int i=1;i<=m*n;i++){
		p++;
		if(a[p]==r2){
			r1=p;
		}
	}
	if(r1%m==0) c=r1/m;
	else c=r1/m+1;
	if(c%2==1){
		r=r1%m;
	}
	else{
		if(r1%m==0) r=1;
		else r=n-r1%m+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
