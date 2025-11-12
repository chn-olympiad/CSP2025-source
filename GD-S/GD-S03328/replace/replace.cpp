#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s[200010][3],t[3];
vector<ll>phi;
inline ll kmp(string mo,string zhu){
	string s=mo+'#'+zhu;
	ll m=mo.size();
	phi.resize(s.size()+3);
	for(ll i=0;i<s.size();i++)phi[i]=0;
	for(ll i=1;i<s.size();i++){
		ll len=phi[i-1];
		while(len>0&&s[len]!=s[i])len=phi[len-1];
		if(s[len]==s[i]){
			phi[i]=len+1;
			if(phi[i]==m)return i-2*m;
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
//		cout<<kmp(s[i][1],s[i][2])<<"\n";
	}
	while(q--){
		cin>>t[1]>>t[2];
		ll ma=-1,mi=1e18,cur=0;
		for(ll i=0;i<t[1].size();i++)if(t[1][i]!=t[2][i])ma=max(ma,i),mi=min(mi,i);
		for(ll i=1;i<=n;i++){
			ll pos1=kmp(s[i][1],t[1]),pos2=kmp(s[i][2],t[2]);
			if(pos1==-1||pos2==-1||pos1!=pos2)continue;
			if(pos1<=mi&&pos1+s[i][1].size()-1>=ma)cur++;
		}
		cout<<cur<<"\n";
	}
	return 0;
} 
