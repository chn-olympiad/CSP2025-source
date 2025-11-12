#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL unsigned long long
#define F 233
#define N 5000005
ll n,q;
string A,B;
LL power[N];
unordered_map<LL,ll>mp;
ll cnt;
struct trie{
	ll to[30];
	ll number;
}kong;
vector<trie>tree[N];
ll CNT[N];
unordered_map<LL,ll>yingshe[N];
void add(ll wei,ll u,ll idx,LL hashi,const string &now){
	yingshe[wei][hashi]=u;
	if(idx==now.size()){
		tree[wei][u].number++;
		return;
	}
	hashi=hashi*F+(now[idx]-'a'+1);
	if(tree[wei][u].to[now[idx]-'a'+1]==0){
		tree[wei].push_back(kong);
		tree[wei][u].to[now[idx]-'a'+1]=++CNT[wei];
	}
	add(wei,tree[wei][u].to[now[idx]-'a'+1],idx+1,hashi,now);
}
void work(ll wei,ll u){
	for(ll t=1;t<=26;t++){
		if(tree[wei][u].to[t]){
			tree[wei][tree[wei][u].to[t]].number+=tree[wei][u].number;
			work(wei,tree[wei][u].to[t]);
		}
	}
}
ll HASHI[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	power[0]=1;
	for(ll i=1;i<=5000000;i++){
		power[i]=power[i-1]*F;
	}
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>A>>B;
		if(A==B)continue;
		ll sz=A.size();
		ll l,r;
		for(ll j=0;j<sz;j++){
			if(A[j]!=B[j]){
				l=j;
				break;
			}
		}
		for(ll j=sz-1;j>=0;j--){
			if(A[j]!=B[j]){
				r=j;
				break;
			}
		}
		LL s1=0,s2=0,s4=0;
		for(ll j=l-1;j>=0;j--){
			s1=s1*F+(A[j]-'a'+1);
		}
		for(ll j=l;j<=r;j++){
			s2=s2*F+(A[j]-'a'+1);
			s4=s4*F+(B[j]-'a'+1);
		}
		LL all_hashi=s1*power[5000000]+s2*power[3000000]+s4*power[1000000];
		ll wei;
		if(mp[all_hashi]){
			wei=mp[all_hashi];
		}
		else{
			mp[all_hashi]=++cnt;
			wei=cnt;
			tree[wei].push_back(kong);
		}
		string use="";
		for(ll j=r+1;j<sz;j++){
			use+=A[j];
		}
		add(wei,0,0,0,use);
	}
	for(ll i=1;i<=cnt;i++){
		work(i,0);
	}
	while(q--){
		cin>>A>>B;
		ll sz=A.size();
		ll l,r;
		for(ll j=0;j<sz;j++){
			if(A[j]!=B[j]){
				l=j;
				break;
			}
		}
		for(ll j=sz-1;j>=0;j--){
			if(A[j]!=B[j]){
				r=j;
				break;
			}
		}
		LL s1=0,s2=0,s4=0;
		for(ll j=l;j<=r;j++){
			s2=s2*F+(A[j]-'a'+1);
			s4=s4*F+(B[j]-'a'+1);
		}
		HASHI[r]=0;
		for(ll j=r+1;j<sz;j++){
			HASHI[j]=HASHI[j-1]*F+(A[j]-'a'+1);
		}
		ll answer=0;
		for(ll j=l;j>=0;j--){
			if(j!=l)s1=s1*F+(A[j]-'a'+1);
			LL all_hashi=s1*power[5000000]+s2*power[3000000]+s4*power[1000000];
			if(mp[all_hashi]==0)continue;
			ll wei=mp[all_hashi];
			ll L=r,R=sz-1;
			while(L<R){
				ll mid=L+R+1>>1;
				if(yingshe[wei].find(HASHI[mid])!=yingshe[wei].end())L=mid;
				else R=mid-1;
			}
			answer+=tree[wei][yingshe[wei][HASHI[L]]].number;
		}
		cout<<answer<<endl;
	}
	return 0;
}
