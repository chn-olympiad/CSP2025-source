//100 YangShao_Culture
#include<bits/stdc++.h>
using namespace std;
int n,m;
int k=1,s;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		if(i==1)	s=a;
		k+=(a>s);
	}
	int l=(k+n-1)/n,h=(k-1)%n+1;
	cout<<l<<" ";
	cout<<(l&1?h:n-h+1);
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
} 
