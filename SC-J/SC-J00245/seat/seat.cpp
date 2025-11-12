#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) b++;
	}
	if(b%n!=0){
		cout<<b/n+1<<" ";
		if(b%(2*n)!=0){
			if(b%(2*n)<=n) cout<<b%(2*n);
			else cout<<(2*n)-b%(2*n)+1;
		}
		else cout<<1;
	} 
	else{
		cout<<b/n<<" ";
		if(b%(2*n)!=0){
			if(b%(2*n)<=n) cout<<b%(2*n);
			else cout<<(2*n)-b%(2*n)+1;
		}
		else cout<<1;
	}
	return 0;	
}