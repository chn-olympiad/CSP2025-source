#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll pjn,pjq;cin>>pjn>>pjq;
	vector<pair<string,string>> A(pjn+1);
	for(ll i=1;i<=pjn;i++){
		string a,b;cin>>a>>b;
		A[i]={a,b};
	}
	while(pjq--){
	ll ans=0;
		string pjt1,pjt2;cin>>pjt1>>pjt2;
		for(ll i=1;i<=pjn;i++){
			ll pjf1=(pjt1.find(A[i].first)),pjf2=pjt2.find(A[i].second);
			bool x=(pjf1<pjt1.size() && pjf2<pjt2.size() && pjf1==pjf2);
			string a=pjt1.substr(pjf1+A[i].first.size(),pjt1.size()-(pjf1+A[i].first.size())+1);
			string b=pjt2.substr(pjf2+A[i].second.size(),pjt2.size()-(pjf2+A[i].second.size())+1);
			if(a!=b)x=0;
			ans+=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
