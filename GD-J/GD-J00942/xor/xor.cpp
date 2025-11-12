#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k;
int p[N],dp[N],pre[N];
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		p[i]=x^p[i-1];
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		if(mp.find(p[i]^k)!=mp.end()){
			int j=mp[p[i]^k];
			dp[i]=pre[j]+1;
		}
		pre[i]=max(pre[i-1],dp[i]);
		mp[p[i]]=i;
	}
	cout<<pre[n];
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

5 2
2 2 2 2 2

5 2
2 0 2 0 2

5 0
2 1 2 1 3

1 1
1

1 2
0
*/
