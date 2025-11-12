#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],sum,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>a[1][1]){
				sum++;
			}
		}
	}
	if(sum==0){
		cout<<1<<" "<<1;
		return 0;
	}
	if(sum==n*m-1){
		cout<<m<<" "<<n;
		return 0;
	}
	if(n==1){
		cout<<sum+1<<" "<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<" "<<sum+1;
		return 0;
	}


	if(sum%n==0||sum/n==0){
		l=1+sum/n;
	}	
	else{
		l=sum/n;
	}
	
	
	if(sum%n==0){
		h=1;
	}
	if(sum/n==1){
		h=sum/n+1;
	}
	else{
		h=1+sum%n;
	}
	cout<<l<<" "<<h;
	return 0;
	
}
