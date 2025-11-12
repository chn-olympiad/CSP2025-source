#include<bits/stdc++.h>
using namespace std;

ifstream fin("xor.in");
ofstream fout("xor.out");
#define cin fin
#define cout fout

const int N=5e5+5;

int n,k;

unordered_map<int,int> f;

signed main(){
	cin>>n>>k;
	f[0]=0;
	int pre=0,las=0,ans=0;
	for(int i=1;i<=n;++i){
		int a; cin>>a;
		pre^=a;
		if(f.count(pre^k)) las=f[pre^k]+1;
        else las=0;
		ans=max(ans,las);
		f[pre]=max(f[pre],ans);
        // cerr<<i<<" "<<pre<<" "<<las<<" "<<(pre^k)<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(),fin.close(),fout.close(); }
} wtl;