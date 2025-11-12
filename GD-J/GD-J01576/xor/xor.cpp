#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000010],sum[1000010];
void solve(){
	map<int,int> m;
	int lst=0,ans=0;
	m[sum[0]]++;
	for(int i=1;i<=n;++i){
		int x=k^sum[i];
		if(m[x]){
			ans++;
			m.clear();
			
		}
		m[sum[i]]++;
	}
	cout << ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >> k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
