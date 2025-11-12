#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1],p;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=n*m-i+1;
			break;
		}
	}
	if(p%n!=0){
		int q=p/n+1;
		cout<<q<<' ';
		if(q%2!=0){
			p%=n;
			cout<<p;
		}
		else{
			p%=n;
			cout<<m-p+1;
		}
	}
	else{
		int q=p/n;
		cout<<q<<' ';
		if(q%2!=0){
			cout<<n;
		}
		else{
			p%=n;
			cout<<1;
		}
	}
	return 0;
}
