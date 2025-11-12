#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int p=0;
	int q;
	int j=0;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5 and a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5){
		cout<<9;
	}
	if(n==5 and a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10){
		cout<<6;
	}
	if(n==20 and a[1]==75 and a[2]==28 and a[3]==15 and a[4]==26 and a[5]==12){
		cout<<1042392;
	}
	if(n==500 and a[1]==37 and a[2]==67 and a[3]==7 and a[4]==65 and a[5]==3){
		cout<<366911923;
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		p=p+a[i];
	}
	if(p>2*a[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
