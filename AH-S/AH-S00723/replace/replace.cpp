#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define SZ(x) ((x).size())
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define fi first
#define se second
#define pb push_back
#define F(x) ((x) % P)
#define FE(x) ((x) %= P)
using namespace std;
using ll = long long;
using db = double;
using PII = pair<int,int>;
using PLL = pair<ll,ll>;
constexpr ll infL = 1ll << 30;
constexpr int infI = 1 << 30;

const int N = 2e5 + 10;

int n,q;

int a[N];

unordered_map<int,int> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	if(n <= 100){
		
	}
	rep(i,1,n){
		string s1,s2;
		cin >> s1 >> s2;
		int x1 = s1.find('b'),x2 = s2.find('b');
		mp[x2 - x1]++;
		//after replace,the b will move how many girds to the right
	}
	while(q--){
		string s1,s2;
		cin >> s1 >> s2;
		int x1 = s1.find('b'),x2 = s2.find('b');
		printf("%d\n",mp[x2 - x1]);
	}
	return 0;
}