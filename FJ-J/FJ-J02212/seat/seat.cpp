#include <bits/stdc++.h>
using namespace std;
int add(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int b=a[1];
	sort(a+1,a+n*m,add);
	for(int i=1;i<=m*n;i++){
		if(a[i]==b){
			cout<<1+i%n<<" ";
			if(i%n!=0 &&i/n%2!=0){
				cout<<n-(i-i/n*n)+1;
			}
			if(i%n!=0 && i/n%2==0){
				cout<<i-i/n*n;
			}
			if(i%n==0){
				cout<<i;
			}
			return 0;
		}
	}
	
	return 0;
}
