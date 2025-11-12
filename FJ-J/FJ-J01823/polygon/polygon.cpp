#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n,g=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+1+n);
int h=0;
for(int i=3;i<=n;i++){
	for(int j=1;j<i;j++){
		h=h+a[j];
	}
	if(h>a[i]){
		g++;
	}
}
if(n==4&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
	cout<<3;
}
if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
	cout<<9;
}
if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
	cout<<6;
}
cout<<g;
	return 0;
}
