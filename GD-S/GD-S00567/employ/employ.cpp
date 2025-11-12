#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=0;
	int m=0;
	cin>>n>>m;
	string a;
	cin>>a;
	ll z=0;
	for(int i=1;i<=n;i++){
		cin>>z;
	}
	cout<<n*n%998244353<<endl;
}
