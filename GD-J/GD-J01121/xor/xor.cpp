#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
struct node{
	int l, r, sum;
};
int n,m,sum,now;
int a[N];
int b[N];
bool vis[N];
unordered_map<int, int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		b[i] = (b[i - 1] ^ a[i]);
	}
	mp[0] = 0;
	vis[0] = true;
	for(int i = 1; i <= n; i++){
		int t = (m ^ b[i]);
		if(vis[t] == true){
			if(mp[t] + 1 > now){
				now = i;
				sum++;
			}
		}
		vis[b[i]] = true;
		mp[b[i]] = i;
	}
	printf("%lld",sum);
	return 0;
}
/*
4 2
2 1 0 3
*/
