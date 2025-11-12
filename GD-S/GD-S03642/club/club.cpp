#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
int n,t[5];
struct st{
	pair<ll,int> a1,a2;
}s[100005];
inline pair<ll,int> ma(pair<ll,int> a,pair<ll,int> b){
	return a.first>b.first?a:b;
}
st ne(ll a,ll b,ll c){
	st r;
	r.a1=ma({a,1},ma({b,2},{c,3}));
	if(a==r.a1.first){
		r.a2=ma({b,2},{c,3});
	}
	if(b==r.a1.first){
		r.a2=ma({a,1},{c,3});
	}
	if(c==r.a1.first){
		r.a2=ma({b,2},{a,1});
	}
	return r;
}
bool cmp(st a,st b){
	ll ai=a.a1.first-a.a2.first;
	ll bi=b.a1.first-b.a2.first;
	return ai>bi;
}
int man(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		s[i]=ne(a,b,c);
	}
	sort(s+1,s+1+n,cmp);
	ll ans=0;
	t[1]=t[2]=t[3]=0;
	for(int i=1;i<=n;i++){
		if(t[s[i].a1.second]==n/2){
			t[s[i].a2.second]++;
			ans+=s[i].a2.first;
		}
		else{
			t[s[i].a1.second]++;
			ans+=s[i].a1.first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		man();
	}
	return 0;
}
