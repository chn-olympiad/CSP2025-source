#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[15][15],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>=a[1][1])sum++;
		}
	}
	ll x=(sum%n==0)?(sum/n):(sum/n+1),y;sum%=n;
	if(x%2==1)y=(sum==0)?(n):(sum);
	else y=(sum==0)?(1):(n-sum+1);
	cout<<x<<" "<<y;
	return 0;
}
