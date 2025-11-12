#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,a[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}sum++;
	ll l=sum/n,r=sum%n;
	if(sum%n>0) l++;
	if(sum%n==0) r=n;
	if(l%2==0) r=n-r+1;
	cout<<l<<" "<<r<<"\n";
	return 0;
} 
