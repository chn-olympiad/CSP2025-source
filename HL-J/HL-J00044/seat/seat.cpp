#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int p;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			p=n*m-i+1;
			break;
		}
	}
	if(p%n==0){
		cout<<p/n<<" ";
		if((p/n)%2==1){
			cout<<n;
		}
		else cout<<n+1;
	}
	else {
		cout<<p/n+1<<" ";
		if((p/n+1)%2==1){
			cout<<p%n;
		}
		else cout<<n-p%n+1;
	}
	return 0;
}
