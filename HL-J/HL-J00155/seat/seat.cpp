#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+k+1);
	for(int i=k,j=1;i>=1;i--,j++){
		if(a[i]==ans){
			ans=j;
			break;
		}
	}
	if(ans%n==0){
		cout<<ans/n<<' ';
	}
	else{
		cout<<ans/n+1<<' ';
	}
	if(ans%(n*2)==0){
		cout<<1;
	}
	else if(ans%n==0){
		cout<<n;
	}
	else if(ans%(n*2)>=n-1){
		cout<<n-(ans%n-1);
	}
	else{
		cout<<ans%n;
	}
	return 0;
} 
