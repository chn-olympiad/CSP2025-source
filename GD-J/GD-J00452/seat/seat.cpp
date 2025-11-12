#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105],pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		pm+=a[i]>a[1];
	}
	ll c=(pm%n==0?pm/n:pm/n+1),r;
	cout<<c<<' ';
	if(c%2)r=(pm%n==0?n:pm%n);
	else r=(pm%n==0?1:n-pm%n+1);
	cout<<r;
	return 0;
}
