#include<bits/stdc++.h>
#define int unsigned long long
#define pii pair<int,int>
using namespace std;
const int bas=19260817;
const int N=2e5+5,M=5e6+5;
int n,q,tot,pre[M],suf[M];
map<pii,int>mp;
struct node{int lenl,lenr,hs,ht;};
vector<node>v[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		if(s==t)continue;
		int m=s.size(),l,r,hs=0,ht=0;
		s=' '+s,t=' '+t;
		for(int j=1;j<=m;j++)if(s[j]!=t[j])r=j;
		for(int j=m;j>=1;j--)if(s[j]!=t[j])l=j;
		for(int j=l;j<=r;j++)hs=hs*bas+s[j],ht=ht*bas+t[j];
		pii tmp={hs,ht};hs=ht=0;
		for(int j=l-1;j>=1;j--)hs=hs*bas+s[j];
		for(int j=r+1;j<=m;j++)ht=ht*bas+s[j];
		if(!mp.count(tmp))mp[tmp]=++tot;
		int kk=mp[tmp];
		v[kk].push_back({l-1,m-r,hs,ht});
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int m=s.size(),l,r,hs=0,ht=0;
		s=' '+s,t=' '+t;
		for(int j=1;j<=m;j++)if(s[j]!=t[j])r=j;
		for(int j=m;j>=1;j--)if(s[j]!=t[j])l=j;
		for(int j=l;j<=r;j++)hs=hs*bas+s[j],ht=ht*bas+t[j];
		pre[l]=suf[r]=0;
		for(int i=l-1;i>=1;i--)pre[i]=pre[i+1]*bas+s[i];
		for(int i=r+1;i<=m;i++)suf[i]=suf[i-1]*bas+s[i]; 
		pii tmp={hs,ht};
		int num=mp[tmp],ans=0;
		for(int i=0;i<v[num].size();i++){
			int ll=v[num][i].lenl,lr=v[num][i].lenr;
			if(l-1<ll||m-r<lr)continue;
			if(pre[l-ll]==v[num][i].hs&&suf[r+lr]==v[num][i].ht)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
