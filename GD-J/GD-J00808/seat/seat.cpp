#include<bits/stdc++.h>
using namespace std;
int a[105];
int f[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
	for(int k=1;k<=n*m;k++){
		int i,j;
		if(k%n==0)i=k/n;
		else i=k/n+1; 
	
		if(i%2){
			if(k%n==0)j=n;
			else j=k%n;
		}
		else{
			if(k%n==0)j=1;
			else j=(n+1)-(k%n);
		}
		if(a[k]==t){
			cout<<i<<" "<<j;
			break;
		}
	}

	return 0;
} 
