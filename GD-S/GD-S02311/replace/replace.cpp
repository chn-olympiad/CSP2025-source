#include<bits/stdc++.h>
#define N 200009
#define ll long long
using namespace std;
ll rt2[N];
ll tot=0,rt[N],trie[1000009][26];
vector<ll>bz[1000009];
struct node{
	string s;
	ll l,r,id;
};
map<pair<string,string>,ll>q;
vector<node>g[N];
void insert(string s,ll rt,ll st,ll id){
	for(ll i=st;i>=0;i--){
		ll now=s[i]-'a';
		if(!trie[rt][now])trie[rt][now]=++tot;
		rt=trie[rt][now];
	}
	bz[rt].push_back(id);
}
void in2(string s,ll rt,ll st,ll id){
	ll len=s.size();
	for(ll i=st;i<len;i++){
		ll now=s[i]-'a';
		if(!trie[rt][now])trie[rt][now]=++tot;
		rt=trie[rt][now];
	}
	bz[rt].push_back(id);
}
ll vis[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,Q,num=0;
	cin>>n>>Q;
	for(ll i=1;i<=n;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		string s3="",s4="";
		ll len=ss1.size(),l=len,r=len-1;
		for(ll j=0;j<len;j++)
			if(ss1[j]!=ss2[j]){
				l=j;
				break;
			}
		for(ll j=len-1;j>=0;j--)
			if(ss1[j]!=ss2[j]){
				r=j;
				break;
			}
		for(ll j=l;j<=r;j++)s3+=ss1[j],s4+=ss2[j];
		if(q[{s3,s4}]==0){
			num++;
			q[{s3,s4}]=num;
		}
		ll no=q[{s3,s4}];
		g[no].push_back({ss1,l,r,i});
	//	cout<<no<<" "<<ss1<<" "<<l<<" "<<r<<" "<<i<<endl;
	}
	for(ll i=1;i<=num;i++){
		rt[i]=++tot;
		rt2[i]=++tot;
		for(ll j=0;j<g[i].size();j++){
			string s=g[i][j].s;
			ll l=g[i][j].l,r=g[i][j].r;
			ll id=g[i][j].id;
			insert(s,rt[i],l-1,id);
			in2(s,rt2[i],r+1,id);
		}
	}
	for(ll i=1;i<=Q;i++){
		for(ll j=1;j<=n;j++)vis[j]=0;
		string ss1,ss2;
		cin>>ss1>>ss2;
		string s3="",s4="";
		ll len=ss1.size(),l=len,r=len-1;
		for(ll j=0;j<len;j++)
			if(ss1[j]!=ss2[j]){
				l=j;
				break;
			}
		for(ll j=len-1;j>=0;j--)
			if(ss1[j]!=ss2[j]){
				r=j;
				break;
			}
		for(ll j=l;j<=r;j++)s3+=ss1[j],s4+=ss2[j];
		ll no=q[{s3,s4}];
		if(no==0){
			printf("0\n");
			continue;
		}
		ll ans=0;
		for(ll j=0;j<g[no].size();j++){
			string sss=g[no][j].s;
			ll l=g[no][j].l,r=g[no][j].r;
			ll id=g[no][j].id;
			if(l-1<0&&r+1>=sss.size())ans++;
			else if(l-1<0||r+1>=sss.size())vis[id]=1;
		}
		ll rt1=rt[no];
		for(ll j=l-1;j>=0;j--){
			ll now=ss1[j]-'a';
			if(!trie[rt1][now])break;
			rt1=trie[rt1][now];
			for(ll k=0;k<bz[rt1].size();k++){
				if(vis[bz[rt1][k]])ans++;
				vis[bz[rt1][k]]=1;
			}
		}
		rt1=rt2[no];
		for(ll j=r+1;j<len;j++){
			ll now=ss1[j]-'a';
			if(!trie[rt1][now])break;
			rt1=trie[rt1][now];
			for(ll k=0;k<bz[rt1].size();k++){
				if(vis[bz[rt1][k]])ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
