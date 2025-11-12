#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,side[5008],prefix[5008],t,v[5008],ans;
void search(int tot,int maxs,int i){
	if(tot>2*maxs){
		ans=(ans+1)%MOD;
	}
	if(i==1) return;
	for(int j=1;j<i;j++) search(tot+side[j],maxs,j);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> side[i];
	sort(side+1,side+1+n);
	for(int i=1;i<=n;i++){
		prefix[i]=prefix[i-1]+side[i];
	}
	for(int i=n;i>=1;i--){
		if(prefix[i-1]>side[i]){
			
			search(side[i],side[i],i);
		}
	}
	cout << ans;
	return 0;
}
