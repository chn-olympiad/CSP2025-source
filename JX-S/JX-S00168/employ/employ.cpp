#include<bits/stdc++.h>
using namespace std;
int ans=1,n,m;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ans=(ans*(n-i))%MOD;
	}
	for(int i=2;i<=m;i++){
		ans=ans/(m%MOD);
	}
	cout<<ans;
	return 0;
}
