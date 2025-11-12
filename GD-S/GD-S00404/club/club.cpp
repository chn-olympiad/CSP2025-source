#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using VI=vector<ll>;
using PI=pair<int,int>;
const int maxn=1e5+5;
struct node{ll a,b,c;}e[maxn];
bool cmp(ll &a,ll &b){return a>b;}
void solve(VI &x,int maxx,ll &sum){
	sort(begin(x),end(x),cmp);
	while((int)x.size()>maxx){
		ll w=x.back();sum-=w;x.pop_back();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		ll n,ans=0,maxx;cin>>n;maxx=n/2;
		VI A,B,C;ll suma=0,sumb=0,sumc=0;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			ll w=max(e[i].a,max(e[i].b,e[i].c));
			if(w==e[i].a)A.push_back(min(e[i].a-e[i].b,e[i].a-e[i].c)),suma+=w;
			else if(w==e[i].b)B.push_back(min(e[i].b-e[i].a,e[i].b-e[i].c)),sumb+=w;
			else C.push_back(min(e[i].c-e[i].a,e[i].c-e[i].b)),sumc+=w;
		}
		if((int)A.size()>maxx)solve(A,maxx,suma);
		else if((int)B.size()>maxx)solve(B,maxx,sumb);
		else if((int)C.size()>maxx)solve(C,maxx,sumc);
		ans+=suma+sumb+sumc;cout<<ans<<"\n";
	}
	return 0;
}
