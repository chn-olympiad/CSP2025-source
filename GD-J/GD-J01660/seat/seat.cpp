#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15];
bool cmp(int a,int b){
	return a>b;
}
int b;
int c;
int r;
int d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a,a+n*m+1,cmp);
	/*for(int i=0;i<=n*m;i++){
		cout<<a[i]<<endl;
	}*/
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			c=i+1;
		}
	}
	int num=c/(2*n);
	c%=2*n;
	//cout<<num<<c;
	if(c>n){
		r=2*n-c+1;
		d=2*num+2;
	}
	else{
		r=c;
		d=2*num+1;
	}
	cout<<d<<' '<<r<<endl;
	return 0;
}
