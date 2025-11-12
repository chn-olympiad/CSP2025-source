#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[109],ss=0,mm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	for(int i=1;i<=m*n;i++){
		for(int i=1;i<=m*n;i++){
			if(a[i+1]>a[i]){
				ss=a[i];
				a[i]=a[i+1];
				a[i+1]=ss;
			}
		}
	}
	int hh;
	for(int i=1;i<=m*n;i++){
		if(a[i]==num){
			hh=i;
		}
	}
	if(hh<n){
		cout<<'1'<<" "<<hh;
	}
	else{
		int nn=(hh-(hh%n))/n;
		if(hh%n!=0) nn++;
		cout<<nn<<' ';
		if(nn%2!=0){
			cout<<hh%n;
		}
		else cout<<(n+1)-(hh%n);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
