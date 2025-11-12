#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define lb long double
#define re register
#define endl '\n'
#define pii pair<int,int>
#define fir first
#define sec second
const int N=5e5+2,M=2e6;
int n,k,a[N],b[M],mn[N],mx[N],dp[N];

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	memset(b,-1,sizeof(b));
	freop("xor");
//以上为初始化
//--------------------------------------
	cin >> n >> k;
	for(int i = 1;i<=n;++i){
		cin >> a[i],a[i]^=a[i-1];
		int t=k^a[i];b[a[i-1]]=i-1;
		if(~b[t]) mn[i]=b[t],dp[i]=mx[mn[i]]+1;
		mx[i]=max(mx[i-1],dp[i]);
	}
	cout << mx[n] << endl;
	return 0;
}
/*

*/


