#include<bits/stdc++.h>
using namespace std;
int n,k,x,a,ans;
map<int,int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	m[0]=1;
	for(int i=1;i<=n;i++) {
		cin>>x;
		a=a^x;
		int t=a^k;
		if(m[t]) {
			ans++;
			m.clear();
		}
		m[a]=1;
	}
	cout<<ans;
	
	return 0;
}
