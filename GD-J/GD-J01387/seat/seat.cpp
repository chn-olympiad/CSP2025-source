#include<bits/stdc++.h>
using namespace std;
int n,m,a1,x;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		x++;
		if(a[i]==a1)break;
	}
	if(x%n==0){
		cout<<x/n<<' '; 
		if((x/n)%2==1)cout<<n;
		else cout<<1;
		return 0;
	}
	if(x%n!=0){
		cout<<x/n+1<<' ';
		if((x/n+1)%2==1)cout<<x%n;
		else cout<<n-x%n+1;
		return 0;
	}
	return 0;
}
