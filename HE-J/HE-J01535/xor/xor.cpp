#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
	ll xo;
};
struct pt{
	int l,r;
};
ll n,k,cnt;
ll a[N];
ll xosum[N];
set<node> s[N];
set<pt> sp;
bool check(node p){
	for(auto it:sp){
		if(e.r>=p.l&&e.r<=p.r) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		xosum[i]=xosum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i-1;j<=n;j++){
			s[i].insert({j-i+1,j,xosum[j]^xosum[j-i]});
		}
	}
	int nl,nr;
	for(int i=1;i<=n;i++){
		for(auto it:s[i]){
			if(it.xo==k&&i==1)(
				sp.insert({it.l,it.r});
			)
			if(i!=1){
				if(it.xo==k&&check(it)){
					cnt++;
					sp.insert({it.l,it.r});
			}
		}
	}
	cout<<cnt;
	return 0;
} 
