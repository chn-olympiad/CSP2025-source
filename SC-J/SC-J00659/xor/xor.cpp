#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
void solveA(){
	cout<<n/2;
	return ;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0&&a[1]==1){
		bool flag=true;
		for(int i=1;i<n;i++){
			if(a[i+1]!=a[i]) flag=false;
		}
		if(flag==true) solveA();
	}
	
	return ;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	return 0;
}	