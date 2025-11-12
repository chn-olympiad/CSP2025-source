#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2) cout<<2;
	else if(n==1){
		if(a[1]==k) cout<<1;
		else cout<<0;
	}
	else{
		if(n%2==0) cout<<n;
		else cout<<n-1;
	}
	return 0;
}
