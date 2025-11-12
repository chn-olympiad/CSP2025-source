#include<bits/stdc++.h>
#define pir pair<ull,ull>
using namespace std;
using ull=unsigned long long;
constexpr int MN=1e6+15;
constexpr ull base=13131;
int n,q;
ull pw[MN],tmps[MN],tmpt[MN];
map<pir,bool> vis;

namespace Hash{

void dohsh(const string &st,ull hsh[]){
	for(int i=0;i<st.length();i++){
		hsh[i+1]=hsh[i]*base+st[i];
	}
}

ull gethshst(const string &st){
	ull ret=0;
	for(auto p:st){
		ret=ret*base+p;
	}
	return ret;
}

ull gethsh(ull hsh[],int l,int r){
	if(l>r) return 0;
	return hsh[r]-hsh[l-1]*pw[r-l+1];
}

void initpw(){
	pw[0]=1;
	for(int i=1;i<MN;i++) pw[i]=pw[i-1]*base;
}

}



int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Hash::initpw();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		vis[pir(Hash::gethshst(a),Hash::gethshst(b))]=1;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.length()!=t.length()){
			cout<<0<<'\n';
			continue;
		}
		int lens=s.length(),lent=t.length(),ret=0;
		Hash::dohsh(s,tmps);
		Hash::dohsh(t,tmpt);
		for(int l=1;l<=lens;l++){
			for(int r=l;r<=lens;r++){
				auto hshs=Hash::gethsh(tmps,l,r);
				auto hsht=Hash::gethsh(tmpt,l,r);
				if(tmps[l-1]==tmpt[l-1]&&Hash::gethsh(tmps,r+1,lens)==Hash::gethsh(tmpt,r+1,lent)){
					ret+=vis[pir(hshs,hsht)];
				}
			}
		}
		cout<<ret<<'\n';
	}

	return 0;
}
