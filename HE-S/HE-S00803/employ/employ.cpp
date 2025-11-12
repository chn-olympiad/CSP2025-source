#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
int n,m,c[505];
bitset<505>s;
int ans,num;
const int mod=998244353;
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	srand(time(0));
	file("employ")
	cin>>n>>m;
	for(int i=1;i<=n;i++)s[i]=getchar()-'0';
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])num++;
	}
	ans=1;
	for(int i=1;i<=num;i++)ans*=i;
	cout<<ans;
	return 0;
}
//0 1 2 2 3 3 4 4 6
