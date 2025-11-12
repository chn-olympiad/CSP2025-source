#include<bits/stdc++.h>
using namespace std;
long long a[200];
int cc(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int ans=a[1];
	sort(a+1,a+1+n*m,cc);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			ans=i;
		}
	}if(ans%n==0){
		int yy=ans/n;
		cout<<yy<<" ";
		if(yy%2==1){
			cout<<n;
		}else cout<<1;
	}else{
		cout<<ans/n+1<<" ";
		if((ans/n+1)%2==1){
			cout<<ans%n;
		}else cout<<n-(ans%n)+1;
	}
	
	return 0;
}
