#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb emplace_back
using namespace std;
const int N=2e5+5,M=5e6+5,p=13331;
int n,Q;
int ans[N];
struct node {
	int l,r,id;
	//id=0 -> modify
};
bool cmp(node x,node y) {
	return x.r<y.r || x.r==y.r && x.l<y.l || x.r==y.r && x.l==y.l && x.id<y.id;
}
map<pair<ull,ull>,vector<node>> v;
int t[M];
void upd(int x,int y) {
	for(; x<M; x+=x&-x) t[x]+=y;
}
int ask(int x) {
	int ans=0;
	for(; x>0; x-=x&-x) ans+=t[x];
	return ans;
}
int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	string s1,s2;
	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;
		int sz=s1.size(),l=0,r=sz-1;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		ull h1=0,h2=0;
		for(int j=l; j<=r; j++) {
			h1=h1*p+(s1[j]-'a'+1);
			h2=h2*p+(s2[j]-'a'+1);
		}
//		cout<<h1<<' '<<h2<<' '<<h1-h2<<'\n';
		v[make_pair(h1,h2)].pb(node{l+1,sz-r,0});
	}
	for(int i=1; i<=Q; i++) {
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) continue;
		int sz=s1.size(),l=0,r=sz-1;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		ull h1=0,h2=0;
		for(int j=l; j<=r; j++) {
			h1=h1*p+(s1[j]-'a'+1);
			h2=h2*p+(s2[j]-'a'+1);
		}
//		cout<<h1<<' '<<h2<<' '<<h1-h2<<'\n';
		v[make_pair(h1,h2)].pb(node{l+1,sz-r,i});
	}
	for(auto it:v) {
		auto v=it.second;
		sort(v.begin(),v.end(),cmp);
		for(auto it:v) {
			if(it.id==0)
				upd(it.l,1);
			else
				ans[it.id]=ask(it.l);
		}
		for(auto it:v)
			if(it.id==0) 
				upd(it.l,-1);
	}
	for(int i=1; i<=Q; i++)
		cout<<ans[i]<<'\n';
	return 0;
}
/*
只能替换一次 
-S考广义SAM? 
S和T只能相差一个子串 
B性质:字符串退化为b的下标,一次转置相当于让下标移动
符合条件的S[i][0]即为 
4 1
aba aab
aab aba
aaba aaab
aabaa aaaba
aabaa aaaba
*/
