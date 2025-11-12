#include<bits/stdc++.h>
using namespace std;
using ll=int;
int flag[1000086]={0};
struct s{
	ll wz,d;
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,o,p,d,ans=0,oo=1;
	map<ll,vector<s> > x;
	cin>>n>>m>>k;
	vector<ll> lz;
	for(int i=1;i<=m;i++){
		cin>>o>>p>>d;
		s ss;
		ss.wz=p;
		ss.d=d;
		x[o].push_back(ss);
		s s1s;
		s1s.wz=o;
		s1s.d=d;
		x[p].push_back(s1s);
	}
	for(int i=1;i<=k;i++){
		cin>>p;
		for(int j=1;j<=n;j++){
			cin>>o;
			x[o].push_back({j,o});
		}
	}
	lz.push_back(1);
	while(oo<=n){
		ll f=INT_MAX;
		for(auto c:lz){
			for(auto t:x[c]){
				if(flag[t.wz]==0){
					f=min(f,t.d);
				}
			}
		}for(auto c:lz){
			ll fla=0;
			for(auto t:x[c]){
				if(t.d==f&&flag[t.wz]==0){
					ans+=t.d;
					lz.push_back(t.wz);
					oo++;
					flag[t.wz]=1;
					fla=1;
					break;
				}
			}if(fla)break;
		}
	}cout<<ans;
	return 0;
}