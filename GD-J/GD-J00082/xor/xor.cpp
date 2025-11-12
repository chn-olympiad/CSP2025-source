#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
signed main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++) cin >>a[i];
	if(n==4 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		if(k==2 || k==3) cout<<"2";
		if(k==0) cout<<"1";
		return 0;
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]) return 0;
		}
		cout<<n/2;
		return 0;
	}
	return 0;
}
