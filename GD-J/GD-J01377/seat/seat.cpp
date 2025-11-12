#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[200]={-1};
	int b=0;
	for(int i=1;i<n*m+1;i++){
		cin>>a[i];
	}
	b=a[1];
	int k=1;
	for(int i=2;i<n*m+1;i++){
		if(a[i]>b){
			k++;
		}
	}
	cout<<k/n+int(bool(k%n))<<' ';
	if((k/n+int(bool(k%n)))%2==1){
		if(bool(k%n)){
		cout<<k%n;
		}else cout<<n;
	}else{
		if(bool(k%n)){
		cout<<n-k%n+1;
		}else cout<<1;
	}
	
	return 0;	
} 
