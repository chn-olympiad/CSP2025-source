#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000],b[110][110]; 
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(k==a[i]){
			k=i;
		}
	}
	cout<<k<<'\n';
	if(k<=n) cout<<1<<" "<<k;
	else if(k%n==0){
		if((k%n)%2==0) cout<<1<<" "<<k/n;
		else cout<<k/n<<" "<<n;
	}
	else if((k/n+1)%2==0){
		cout<<(k/n)+1<<" "<<(k/n+1)*n-k+1;
	}
	else if((k/n+1)%2==1){
		cout<<(k/n+1)<<" "<<(k/n+1)*n-k+1;
	}
	return 0;
}
