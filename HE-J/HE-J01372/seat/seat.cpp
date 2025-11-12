#include<bits/stdc++.h>
using namespace std;
int a[201];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,b=0,c,d;
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
		b++;}
	c=a[0];
	for(int j=0;j<b+1;j++){
		for(int d=1;d<b;d++){
			if(a[d]>a[d-1]){
				swap(a[d],a[d-1]);}}}
	for(int i=0;i<b;i++){
		if(a[i]==c)
			c=i+1;
	}
	if(c%n==0){
		d=c/n;
		if(d%2==0){
			cout<<d+1<<" "<<n;
			return 0;
			}
		else
			cout<<d<<" "<<n;
			return 0;}
	if(c%n!=0){
		d=c/n;
		if(d%2==0){
			cout<<d+1<<" "<<c%n;
			return 0;
			}
		else
			cout<<d+1<<" "<<n+1-c%n;
			return 0;}
}
