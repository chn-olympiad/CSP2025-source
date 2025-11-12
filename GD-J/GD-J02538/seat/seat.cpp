#include <bits/stdc++.h>
using namespace std;
int n,m,w[200],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>w[i];
	}
	int a=w[1];
	sort(w+1,w+n*m+1);
	for(int i=1;i<=m*n;i++){
		if(w[i]==a){
			s=n*m-i;
		}
	}
	int b=s/n+1,c=s%n+1;	
	if(b%2==0){
		c=n+1-c;
	}
	cout<<b<<" "<<c;
	
	return 0;
} 
