#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
struct node{
	int l,r;
};
bool cmp(node x,node y){
	return x.l<y.l;
}
vector<node> b(1);
vector<ll> f(1);
ll n,k,a[N];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ll u;
		cin>>u;
		a[i]=a[i-1]^u;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int c=a[r]^a[l-1];
			if(c==k) b.push_back({l,r});
		}
	}
	sort(b.begin()+1,b.end(),cmp);
	f.push_back(1);
	for(int i=2;i<b.size();i++){
		ll ans=1;
		for(int j=1;j<i;j++){
			if(b[j].r<b[i].l) ans=max(ans,f[j]+1);
		}
		f.push_back(ans);
	}
	cout<<f[b.size()-1];
	return 0;
}
