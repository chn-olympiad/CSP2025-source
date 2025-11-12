#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b)	for(int i = (a);i<=(b);i++)
#define lep(i,a,b)	for(int i = (a);i>=(b);i--)
using namespace std;
const int N = 5e6+10;
const int H = 13331;
const int M = 998244353;
int n,q,ans,l,r;
int fac[N],s1[N],s2[N];
string t1,t2;
#define mk(x,y)	make_pair(x,y)
map<pair<int,int>,int> mp;
set<int> S;
inline int Hash(string s){
	int res = 0;
	rep(i,0,(int)s.size()-1){
		res = (res*H%M+(s[i]-'a'+1))%M;
	}
	return res;
}
inline int ask(int l,int r,int s[]){
	return ((s[r]-s[l-1]*fac[r-l+1]%M)%M+M)%M;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>q;
	rep(i,1,n){
		cin>>t1>>t2;
		int x = t1.size();
		S.insert(x);
		int x1 = Hash(t1),x2 = Hash(t2);
		mp[mk(x1,x2)]++;
	}
	fac[0] = 1;
	rep(i,1,3e6)	fac[i] = fac[i-1]*H%M;
	rep(i,1,q){
		cin>>t1>>t2;
		if(t1.size() != t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int m = t1.size();
		t1 = " "+t1;
		t2 = " "+t2;
		rep(j,1,m){
			if(t1[j] != t2[j]){
				l = j;
				break;
			}
		}
		lep(j,m,1){
			if(t1[j] != t2[j]){
				r = j;
				break;
			}
		}
		rep(j,1,m){
			s1[j] = (s1[j-1]*H%M+(t1[j]-'a'+1))%M;
			s2[j] = (s2[j-1]*H%M+(t2[j]-'a'+1))%M;
		}
		ans = 0;
		rep(L,1,l){
			for(auto x:S){
				int R = L+x-1;
				if(R<r || R>m)	continue;
				int x1 = ask(L,R,s1);
				int x2 = ask(L,R,s2);
				ans+=mp[mk(x1,x2)];
			}
		}
		cout<<ans<<"\n";
		rep(j,1,m)	s1[i] = s2[i] = 0;
	}
	return 0;
}
