#include<bits/stdc++.h>
using namespace std;

#define int ll
#define pii pair<int,int>
#define ll long long

#define For(a,b,c) for(int a=(b);a<=(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(c);a--)

int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x=(x*10)+ch-'0';
	return x*f;
}

#define in1(a) a=read()
#define in2(a,b) a=read(),b=read()
#define in3(a,b,c) a=read(),b=read(),c=read()
#define in4(a,b,c,d) a=read(),b=read(),c=read(),d=read()

int n,q;
int pw[2020];
string s[2020][2];
vector<int > h[2020][2],t[2];

const int mod=1e9+9;
const int base=13331;

bool fc(vector<int>h1,vector<int>h2,int l,int r,int opt) {
	int x=0,y=h2.size()-1;
	if(l>r) return 1;
	if(opt==1) {
		return ((h1[r]-(l-1<0?0:h1[l-1]*pw[r-l+1])%mod)+mod)%mod==h2[y];
	} else {
		return ((h1[r]-(l-1<0?0:h1[l-1]*pw[r-l+1])%mod)+mod)%mod==((h2[r]-(l-1<0?0:h2[l-1]*pw[r-l+1])%mod)+mod)%mod;
	}
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	For(i,1,2000) pw[i]=pw[i-1]*base%mod;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	
	For(qwq,1,n) {
		string s1,s2; cin>>s1>>s2;
		s[qwq][0]=s1; int res=0;
		For(i,0,s1.size()-1) res=(res*base+s1[i])%mod,h[qwq][0].push_back(res);
		s[qwq][1]=s2; res=0; 
		For(i,0,s2.size()-1) res=(res*base+s2[i])%mod,h[qwq][1].push_back(res);
	}
	
	while(q--) {
		string t1,t2; cin>>t1>>t2;
		int res=0;t[0].clear(); t[1].clear();
		For(i,0,t1.size()-1) res=(res*base+t1[i])%mod,t[0].push_back(res);
		res=0;
		For(i,0,t2.size()-1) res=(res*base+t2[i])%mod,t[1].push_back(res);
		int ans=0;
		For(i,1,n) if(t1.size()>=s[i][0].size()){
			For(l,0,t1.size()-s[i][0].size()) {
				int r=l+s[i][0].size()-1;
//				cout<<i<<' '<<l<<' '<<r<<'\n';
				if(fc(t[0],h[i][0],l,r,1)&&fc(t[1],h[i][1],l,r,1)&&fc(t[0],t[1],0,l-1,0)&&fc(t[0],t[1],r+1,t1.size()-1,0)) {
					ans++; break;
				}
			} 
		}
		cout<<ans<<'\n';
	}

	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


*/
