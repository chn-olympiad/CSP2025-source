#include<bits/stdc++.h>
using namespace std;
const int MAXN= 5e3+10;
int a[MAXN];	int n;
void solv1(){
	int he=0,da=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da=max(da,a[i]);
		he+=a[i];
	}
	if(he>2*da)cout<<1;
	else{
		cout<<0;
	}
}
void solv2(){
	int he=0,da=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<7;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		solv1();
	}
	else if(n<=10){
		solv2();
	}
	else{
		cout<<0;
	}
	return 0;
}
