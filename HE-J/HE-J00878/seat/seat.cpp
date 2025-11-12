#include<bits/stdc++.h>
using namespace std;
const int N=201;
int m,n,a[N],x=0,c=0,i=0,j=0;
int main(){
	freoppen("seat.in","r","stdin")
	freoppen("seat.out","w","stdout")
	cin>>n>>m;
	c=n*m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[j];}}
	x=a[j];
	sort(a+1,a+c+1);
	for(i=1;i<=n;i++){
		if(i%2!=0){
			for(j=1;j<=n;j++){
				c--;
				if(a[c]==x){
					cout<<i<<" "<<j;
					}}}
		else{
			for(j=1;j<=n;j++){
				c--;
                if(a[c]==n){
					cout<<i<<" "<<j;}
				}
			}
		}
	return 0;
}
