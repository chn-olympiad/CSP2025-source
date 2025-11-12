#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	int num,p=1;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
		num=a[1];
		if(num<a[i])p++;
	}
	int c,r;
	c=p/n;
	if(p%n>0)c++;
	p%=n;
	if(c%2){
		if(p==0)r=n;
		else r=p;
	}
	else{
		if(p==0)r=1;
		else r=n-p+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
