#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

const int N = 1e5 + 5;
ll n,m,ans = 1;

int main(){
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < m;i++)ans *= (n - i),ans %= 998244353;
	cout<<ans;
	return 0;
} 
