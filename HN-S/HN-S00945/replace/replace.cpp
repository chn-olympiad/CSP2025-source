#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll m1=989244353,m2=998244853,bs=10007;
int n,q;
map<pair<ll,ll>,multiset<pair<int,int>>> h1;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,ss;
		cin>>s>>ss;
		if(s==ss) continue;
		int l,r;
		for(int j=0;j<s.length();j++){
			if(s[j]!=ss[j]){
				l=j;
				break;
			}
		}
		for(int j=s.length()-1;j>=0;j--){
			if(s[j]!=ss[j]){
				r=j;
				break;
			}
		}
		ll hs1=0,hs2=0,hs3=0,hs4=0,hs5=0,hs6=0;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+s[j])%m1;
			hs2=(hs2*bs+s[j])%m2;
		}
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+ss[j])%m1;
			hs2=(hs2*bs+ss[j])%m2;
		}
		for(int j=l-1;j>=0;j--){
			hs3=(hs3*bs+s[j])%m1;
			hs4=(hs4*bs+s[j])%m2;
		}
		for(int j=r+1;j<s.length();j++){
			hs5=(hs5*bs+s[j])%m1;
			hs6=(hs6*bs+s[j])%m2;
		}
		h1[{hs1*m2+hs2,hs5*m2+hs6}].insert({hs3,hs4});
	}
	for(int i=1;i<=q;i++){
		string s,ss;
		cin>>s>>ss;
		if(s.length()!=ss.length()){
			cout<<0<<'\n';
			continue;
		}
		int l,r;
		for(int j=0;j<s.length();j++){
			if(s[j]!=ss[j]){
				l=j;
				break;
			}
		}
		for(int j=s.length()-1;j>=0;j--){
			if(s[j]!=ss[j]){
				r=j;
				break;
			}
		}
		ll hs1=0,hs2=0,hs3=0,hs4=0,hs5=0,hs6=0,res=0;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+s[j])%m1;
			hs2=(hs2*bs+s[j])%m2;
		}
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+ss[j])%m1;
			hs2=(hs2*bs+ss[j])%m2;
		}
		set<pair<int,int>> pl;
		pl.insert({0,0});
		for(int j=l-1;j>=0;j--){
			hs3=(hs3*bs+s[j])%m1;
			hs4=(hs4*bs+s[j])%m2;
			pl.insert({hs3,hs4});
		}
		for(int j=r+1;j<s.length();j++){
			if(h1.count({hs1*m2+hs2,hs5*m2+hs6}))
				for(pair<int,int> v:h1[{hs1*m2+hs2,hs5*m2+hs6}])
					if(pl.count(v)) res++;
			hs5=(hs5*bs+s[j])%m1;
			hs6=(hs6*bs+s[j])%m2;
		}
		for(pair<int,int> v:h1[{hs1*m2+hs2,hs5*m2+hs6}])
				if(pl.count(v)) res++;
		cout<<res<<'\n';
	}
	return 0;
}
/*
17:30 wo kan cuo ti mu le,again
18:11 O(n^2logn) if ac i eat shi
*/