#include<bits/stdc++.h>
using namespace std;

const int NM = 5e5;
int G[NM+4],H[NM+4];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i = 1,a;i <= n;i++) cin>>a,G[i] = G[i-1]^a;
	for(int i = 1;i <= n;i++){
		int last = i,cnt = 0;
		for(int j = i;j <= n;j++){
			H[j] = 0;
			if((G[j]^G[last-1]) == k) cnt++,H[j]++,last = j+1;
		}
		for(int j = 1;j < i;j++) cnt += H[j];
		ans = max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
