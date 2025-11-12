#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],b,R,pm,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<m*n;i++){
		for(int j=1;j<m*n;j++){
			b=0;
			if(a[j]<a[j+1]){
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			pm=i;
		}
	}
	if(pm%n==0){
		l=pm/n;
		if(l%2==1){
			h=n;
		}
		else{
			h=1;
		}
	}
	else{
		l=(pm/n)+1;
		if(l%2==1){
			h=pm-(l-1)*n;
		}
		else{
			h=l*n-pm+1;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
