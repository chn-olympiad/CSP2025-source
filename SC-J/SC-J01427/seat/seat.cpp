#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,b[100001],ans=0,m=1,asa=0;
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>b[i];
	}
	int qp=b[0];
	for(int i=0;i<x*y;i++){
		for(int j=m;j<x*y;j++){
			if(b[i]<b[j]){
				ans=b[i];
				b[i]=b[j];
				b[j]=ans;
				ans=0;
			}
			if(j+1==x*y) m++;
		}
	}
	for(int i=0;i<x*y;i++){
		if(b[i]==qp) asa=i+1;
	}
	if(y==1) cout<<1<<" "<<asa;
	if(y==2){
		if(asa<=x){
			 cout<<1<<" "<<asa;
		}
		else {
			cout<<2<<" "<<2*x-asa+1;
		}
	}
	if(x==1&&y!=1&&y!=2){
		cout<<asa<<" "<<1;
	}
	if(x==2&&y!=1&&y!=2){
		if(asa%2==0&&asa/2%2==0) cout<<asa/2<<" "<<1;
		else if(asa%2==0&&asa/2%2!=0) cout<<asa/2<<" "<<2;
		else if(asa%2!=0&&(asa+1)/2%2==0) cout<<(asa+1)/2<<" "<<2;
		else cout<<(asa+1)/2<<" "<<1;
	}
	return 0;
}