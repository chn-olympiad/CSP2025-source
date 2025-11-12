#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n[10][10];
	int a,b;
	int ans=0;
	int c[1000000],tt[1000000];
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	for(int i=0;i<a*b;i++){
		tt[i]=c[i];
	}
	for(int i=a*b;i>0;i--){
		for(int j=0;j<a*b;j++){
			if(c[j]<c[j+1]){
			swap(c[j],c[j+1]);
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i*j<=a*b){
				n[i][j]=c[ans];
				ans++;
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(n[i][j]==tt[0]){
				cout<<i<<" "<<j;
			}
				}
	}
	return 0;}
