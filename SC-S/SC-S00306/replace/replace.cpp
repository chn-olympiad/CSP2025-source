#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull P=1e9+7;
const int maxn=2e5+10;
string sa[maxn],sb[maxn],qa,qb;
ull p[maxn*25],ha[maxn*25],hb[maxn*25];
pair<ull,ull> mp[maxn];
int now,llen[maxn];
int n,q;
inline ull getha(int l,int r){
	if(l>r) return 0;
	return ha[r]-ha[l-1]*p[r-l+1];
}
inline ull gethb(int l,int r){
	if(l>r) return 0;
	return hb[r]-hb[l-1]*p[r-l+1];
}
int len;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=5e6;i++) p[i]=p[i-1]*P;
	for(int i=1;i<=n;++i){
		cin>>sa[i];
		cin>>sb[i];
		ull ha=0,hb=0;
		for(int j=0;j<sa[i].size();++j) ha=ha*P+sa[i][j],hb=hb*P+sb[i][j];
		mp[i]={ha,hb};
		llen[i]=sa[i].size();
	} 
	for(int i=1;i<=q;++i){
		cin>>qa>>qb;
		len=qa.size();
		for(int j=0;j<len;++j) ha[j+1]=ha[j]*P+qa[j],hb[j+1]=hb[j]*P+qb[j];
		int ans=0;
		for(int j=1;j<=n;++j)
			if(mp[j].first==ha[len]&&mp[j].second==hb[len]) ++ans;
		for(int j=1;j<len;++j){
			if(ha[j]!=hb[j]) break;
			for(int k=1;k<=n;++k){
				if(llen[k]+j<=len&&getha(j+1,j+llen[k])==mp[k].first&&gethb(j+1,j+llen[k])==mp[k].second&&getha(j+llen[k]+1,len)==gethb(j+llen[k]+1,len)) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}