#include<iostream>
#include<unordered_map>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
constexpr int N=2e5+10,L=2e6+10;
int n,q;
namespace sub1{
	bool havelen[L];
	ull h1[L],h2[L],base[L];
	ull geth1(int l,int r){
		if(l>r) return 0;
		return h1[r]-h1[l-1]*base[r-l+1];
	}
	ull geth2(int l,int r){
		if(l>r) return 0;
		return h2[r]-h2[l-1]*base[r-l+1];
	}
	int idcnt;
	unordered_map<ull,int> cnt;
	string t1,t2,s1,s2;
	ll res;
	void solve(){
		base[0]=1;
		for(int i=1;i<=2e6;i++) base[i]=base[i-1]*131;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;
			havelen[s1.length()]=1;
			ull h=0;
			for(char c:s1) h=h*131+c;
			for(char c:s2) h=h*131+c;
			++cnt[h];
		}
		while(q--){
			cin>>t1>>t2;
			if(t1.length()!=t2.length()){
				cout<<"0\n";
				continue;
			}
			for(int i=0;i<int(t1.length());i++){
				h1[i+1]=h1[i]*131+t1[i];
				h2[i+1]=h2[i]*131+t2[i];
			}
			res=0;
			for(int len=1;len<=int(t1.length());len++){
				if(!havelen[len]) continue;
				for(int l=1,r=l+len-1;r<=int(t1.length());l++,r++){
					if(geth1(1,l-1)!=geth2(1,l-1)) continue;
					if(geth1(r+1,t1.length())!=geth2(r+1,t1.length())) continue;
					ull hash1=geth1(l,r),hash2=geth2(l,r);
					ull h=hash1*base[len]+hash2;
					auto it=cnt.find(h);
					if(it!=cnt.end()) res+=it->second;
				}
			}
			cout<<res<<'\n';
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	sub1::solve();
	return 0;
}
