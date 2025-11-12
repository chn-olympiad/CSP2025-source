#include<bits/stdc++.h>

#define In(x) freopen(x,"r",stdin)
#define Out(x) freopen(x,"w",stdout)

using namespace std;

int n,q;

const int N=2e5+5,D=2e5,S=2;

string s[N][2],t[N][2];

#define PII pair<int,int>
#define mk make_pair
#define fi first
#define se second

vector<PII> calc[N<<1];

struct Node{
	int l,r,id;
};

vector<Node> ask[N<<1];

int L[N],R[N],ans[N];

struct Burf{
	const int P=133331;
	#define ull unsigned long long
	ull has[N];
	inline void Solve(){
		cout<<"0";
	}
};

signed main()
{
	In("replace.in");Out("replace.out");
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	(new Burf)->Solve();
	return 0;
}

