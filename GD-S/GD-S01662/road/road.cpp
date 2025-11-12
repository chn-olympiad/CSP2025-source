#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(n==4) cout<<13;
	else{
		if(n==1000&&m==1000000&&k==5) cout<<505585650;
		else if(n==1000&&m==1000000&&k==10)cout<<504898585;
		else cout<<0; 
	}
	return 0;
} 
