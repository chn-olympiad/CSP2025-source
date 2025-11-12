#include <bits/stdc++.h>
#define tmxn 200005
#define maxn 5000005
#define ll long long
#define mod 998244353
using namespace std;
const int mmul=713;
struct node{
	int val,id;
	bool friend operator <(node a,node b){
		return a.val<b.val;
	}
}a1[maxn],a2[maxn];
string s1,s2,now;
unordered_map<int,int>mygo;
vector<node>g1[tmxn],g2[tmxn];
ll n,m,cnt,id1,id2,val[tmxn],col[tmxn],l1[tmxn],l2[tmxn],r1[tmxn],r2[tmxn];
ll calc(ll l,ll r){
	if(l>r) return 0;
	ll ans=0;
	for(ll i=l;i<=r;i++){
		ans*=mmul;
		ans+=val[now[i]-'a'+1];
		ans%=mod;
	} 
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	val[0]=1;
	for(ll i=1;i<=26;i++) val[i]=val[i-1]*37%mod;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;now=s1;
		int l=s1.length(),r=-1;
		for(ll j=0;j<s1.length();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(ll j=s1.length()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		if(l>r) continue;
		ll d=calc(l,r);
		now=s2;
		d=d*29+calc(l,r);
		d%=mod;
		now=s1;
		if(!mygo[d]) mygo[d]=++cnt;
		d=mygo[d];
		ll d1=calc(0,l-1);
		g1[d].push_back({d1,i});
		ll d2=calc(r+1,s1.length()-1);
		g2[d].push_back({d2,i});
	}
	id1=id2=1;
	for(int i=1;i<=cnt;i++){
		sort(g1[i].begin(),g1[i].end());l1[i]=id1;
		for(int j=0;j<g1[i].size();j++) a1[id1].val=g1[i][j].val,a1[id1].id=g1[i][j].id,id1++;r1[i]=id1;
		sort(g2[i].begin(),g2[i].end());l2[i]=id2;
		for(int j=0;j<g2[i].size();j++) a2[id2].val=g2[i][j].val,a2[id2].id=g2[i][j].id,id2++;r2[i]=id2;
	}
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;now=s1;
		int l=s1.length(),r=-1;
		for(ll j=0;j<s1.length();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(ll j=s1.length()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		if(l>r) continue;
		ll ans=0;
		ll d=calc(l,r);
		now=s2;
		d=d*29+calc(l,r);
		d%=mod;
		now=s1;
		if(!mygo[d]){
			cout<<"0\n";
			continue;
		}
		d=mygo[d];
		ll d1,p1,d2,p2,mul;
		mul=1;d1=0,d2=0;
		p1=lower_bound(a1+l1[d],a1+r1[d],(node){d1,0})-a1;
		while(p1!=r1[d]&&a1[p1].val==d1) col[a1[p1].id]++,p1++;
		p2=lower_bound(a2+l2[d],a2+r2[d],(node){d2,0})-a2;
		while(p2!=r2[d]&&a2[p2].val==d2){
			col[a2[p2].id]++;
			if(col[a2[p2].id]==2) ans++;
			p2++;
		}
		for(int i=l-1;i>=0;i--){
			d1=(d1+val[now[i]-'a'+1]*mul)%mod;
			mul=mul*mmul%mod;
			p1=lower_bound(a1+l1[d],a1+r1[d],(node){d1,0})-a1;
			while(p1!=r1[d]&&a1[p1].val==d1) col[a1[p1].id]++,p1++;
		}
		for(int i=r+1;i<s1.length();i++){
			d2=(d2*mmul+val[now[i]-'a'+1])%mod;
			p2=lower_bound(a2+l2[d],a2+r2[d],(node){d2,0})-a2;
			while(p2!=r2[d]&&a2[p2].val==d2){
				col[a2[p2].id]++;
				if(col[a2[p2].id]==2) ans++;
				p2++;
			}
		}
		mul=1;d1=d2=0;
		p1=lower_bound(a1+l1[d],a1+r1[d],(node){d1,0})-a1;
		while(p1!=r1[d]&&a1[p1].val==d1) col[a1[p1].id]--,p1++;
		p2=lower_bound(a2+l2[d],a2+r2[d],(node){d2,0})-a2;
		while(p2!=r2[d]&&a2[p2].val==d2) col[a2[p2].id]--,p2++;
		for(int i=l-1;i>=0;i--){
			d1=(d1+val[now[i]-'a'+1]*mul)%mod;
			mul=mul*mmul%mod;
			p1=lower_bound(a1+l1[d],a1+r1[d],(node){d1,0})-a1;
			while(p1!=r1[d]&&a1[p1].val==d1) col[a1[p1].id]--,p1++;
		}
		for(int i=r+1;i<s1.length();i++){
			d2=(d2*mmul+val[now[i]-'a'+1])%mod;
			p2=lower_bound(a2+l2[d],a2+r2[d],(node){d2,0})-a2;
			while(p2!=r2[d]&&a2[p2].val==d2) col[a2[p2].id]--,p2++;
		}
		cout<<ans<<"\n";
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
} 
