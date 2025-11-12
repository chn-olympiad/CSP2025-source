#include<bits/stdc++.h>
using namespace std;
int n,m,c[520],giveup;
long long ly=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ly*=i;
		if(c[i]==0) giveup++;
	}
	for(int i=n;i>n-giveup;i--){
		ly/=i;
	}
	if(n-giveup<m) cout<<0;
	else cout<<ly%998244353;
	return 0;
}
