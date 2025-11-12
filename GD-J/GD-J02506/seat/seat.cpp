#include<bits/stdc++.h>
using namespace std;
int n,m,h[1000],a,b,c;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>h[i];
	a=h[1];
	sort(h+1,h+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(h[i]==a){
			a=n*m-i+1;break;
		}
	}
	if(a%n==0) b=a/n;
	else b=a/n+1;
	if(b%2==0) c=b*n-a+1;
	else c=a+n-b*n;
	cout<<b<<" "<<c;
	return 0;
}
