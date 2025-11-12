#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(k==a[i]){
			k=n*m-i;
		}
	}
	cout<<k/n+1<<" ";
	if((k/n+1)%2==0){
		cout<<n-k%n;
	}else{
		cout<<k%n+1;
	}
	return 0;
} 

