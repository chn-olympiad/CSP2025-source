#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod=998244353*(1e9+7)+2;
inline ull mul(ull x,ull y){
	return (((x*y)-((ull)((long double)x/mod)*y)*mod)+mod)%mod;
}
const ull base=131;
ull hs(string s){
	ull ret=0;
	for(auto i:s){
		ret=(mul(ret,base)+i-'a')%mod;
	}
	return ret;
} 
ull p[5000005],h[2][5000005];
void init_hash(string x,string y){
	p[0]=1;
	for(int i=1;i<x.size();i++){
		h[0][i]=(mul(h[0][i-1],base)+x[i]-'a')%mod;
		p[i]=mul(p[i-1],base);
	}
	for(int i=1;i<y.size();i++){
		h[1][i]=(mul(h[1][i-1],base)+y[i]-'a')%mod;
		p[i]=mul(p[i-1],base);
	}
}
ull geth(int op,int l,int r){
	return (h[op][r]-mul(h[op][l-1],p[r-l+1])+mod)%mod;
}
int n,q;
map<pair<ull,ull>,int>mp;
int main(){
	fstream cin("replace.in",ios::in);
	fstream cout("replace.out",ios::out);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cerr<<i<<'\n';
		string x,y;
		cin>>x>>y;
//		cerr<<hs(x)<<' '<<hs(y)<<'\n';
		mp[make_pair(hs(x),hs(y))]++;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		x.insert(x.begin(),'#');
		y.insert(y.begin(),'#');
		init_hash(x,y);
		int len=min(x.size(),y.size()),ans=0;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=len-i-1;j++){
				if(geth(1,1,i)==geth(0,1,i)&&
				geth(0,x.size()-j,x.size()-1)==geth(1,y.size()-j,y.size()-1)){
//					cerr<<i<<' '<<j<<' '<<i+1<<' '<<x.size()-j-1<<' '<<geth(0,i+1,x.size()-j-1)<<'\n';
					ans+=mp[make_pair(geth(0,i+1,x.size()-j-1),geth(1,i+1,y.size()-j-1))];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
