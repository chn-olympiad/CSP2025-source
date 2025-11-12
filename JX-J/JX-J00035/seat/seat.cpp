#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],t,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	cin>>a[i];
	t=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
	if(a[i]==t) g=n*m-i+1;
	}
	int d=g%n,q=g/n;
	if(d==0){
		if(q%2==1){
		cout<<q<<" "<<n;
		}
		else if(q%2==0){
		cout<<q<<" "<<1;
		}
	}
	else if(q%2==1){
	cout<<q+1<<" "<<n-g%n+1;	
		}
	else if(q%2==0){
		cout<<q+1<<" "<<g%n;
		}
		return 0;
	}
