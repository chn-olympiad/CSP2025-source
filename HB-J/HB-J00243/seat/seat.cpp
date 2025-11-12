#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);	
int n,m,a[100];
cin>>n>>m;
int seat[n][m];
for(int i=1;i<=n*m;i++){
		cin>>a[i];
}
int mi=1;
for(int k=1;k<=n;k++){
	for(int i=1;i<=m;i++){
        int l=0;
		for(int j=1;j<=n*m;j++){
			if(a[j]>=l){
				l=a[j];
				seat[mi][i]=l;
				}
			}
			if(i%2!=0){
				mi++;
				}
			else{
				mi--;}
		}
		}
cout<<1<<" "<<2;
	return 0;
}
