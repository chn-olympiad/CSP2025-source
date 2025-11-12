#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,s=1,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)s++;
	}
	d=(s-1)/n+1;
	s=(s-1)%n+1;
	if(d%2==0)s=n-s+1;
	cout<<d<<' '<<s;
} 
