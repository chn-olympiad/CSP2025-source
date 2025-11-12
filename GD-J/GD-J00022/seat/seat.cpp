#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p=1,r;
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>r){
			p++;
		}
	}
	if(p%n) cout<<p/n+1<<' ';
	else cout<<p/n<<' ';
	if(p%(2*n)>n||p%(2*n)==0){
		if(p%(2*n)==0){
			cout<<1; 
		}
		else{
			cout<<n-(p%n)+1;	
		}
	}
	else{
		if(p%n==0){
			cout<<n;
		}
		else{
			cout<<p%n;
		}
	}
	return 0;
}
