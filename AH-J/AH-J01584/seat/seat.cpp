#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,f=1,m;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a){
			f++;
		}
	}
	int g;
	if(f%n==0) g=f/n;
	else g=f/n+1;
	cout<<g<<" ";
	if(g%2!=0){
		if(f%n==0) cout<<n;
		else cout<<f%n;
	}else{
		if(f%n==0) cout<<1;
		else cout<<g*n-f+1;
	}
	return 0;
}
