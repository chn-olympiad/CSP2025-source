#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=110;
ll n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll cnt=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	ll x=0,y=0;
	x=cnt/n+1;
	if(x%2==1){
		y=cnt%n+1;
	}else{
		y=n-(cnt%n);
	}
	cout<<x<<" "<<y;
	return 0;
} 
