#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001];
int n,m;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t;
	for(int i=0;i<n*m;i++){
		cin>>b[i];if(i==0) t=b[i];
	}
	sort(b,b+n*m);
	
	for(int i=n*m-1;i>=0;i--){
		a[n*m-i-1]=b[i];
		
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			cout<<i/m+1<<' ';
			if(i/m%2==0){
				cout<<i%n+1;
			}else cout<<n-i%n;
		}
	}
	return 0;
} 
