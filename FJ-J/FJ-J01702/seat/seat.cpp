#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=1,q,w;
	cin>>m>>n>>w;
	for(int i=2;i<=m*n;i++){
		cin>>q;
		if(q>w){
			k++;
		}
	}
	if(k%n==0){
		cout<<k/n<<' ';
	}else
		cout<<k/n+1<<' ';
	if(k/n%2==0){
		cout<<k%n<<' ';
	}else if(k/n%2==1){
		if(k%n==0){
			cout<<n<<' ';
		}
		else cout<<n-k%n+1<<' ';
	}	
	return 0;
	
}
