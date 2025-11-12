#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,k;
long long ans;
int x,s1[N],s2[N];
bool vis[M];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>x;
		s1[i]=s1[i-1]^x;
		s2[i]=s1[i]^k;
	}
	vis[s1[0]]=true;
	int l=0;
	for(int i=1;i<=n;i++) {
		if(!vis[s2[i]]) {
			vis[s1[i]]=true;
		}
		else {
			ans++;
			for(int j=l;j<=i-1;j++) {
				vis[s1[j]]=false;
			}
			l=i;
			vis[s1[i]]=true;
		}
	}
	cout<<ans;
	return 0;
}
