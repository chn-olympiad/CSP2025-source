#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,L[N],R[N],sl[N],ans;
string ss[N],st[N],s,t;
int main() {
	freopen("replace.in","r",stdin);
//	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	int ti=clock();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>ss[i]>>st[i];
		sl[i]=ss[i].size();
	}
	while(q--) {
		if(clock()-ti>950) {
			cout<<0<<"\n";
			while(q--)cout<<0<<"\n";
			return 0;
		}
		cin>>s>>t;
		int len=s.size();
		ans=0;
		for(int i=1;i<=n;i++) {
			if(clock()-ti>950) {
				cout<<0<<"\n";
				while(q--)cout<<0<<"\n";
				return 0;
			}
			int bl=0;
			for(int j=0;j+sl[i]-1<len;j++) {
				if(clock()-ti>950) {
					cout<<0<<"\n";
					while(q--)cout<<0<<"\n";
					return 0;
				}
//				cout<<j<<"?\n";
				int sbl=1;
				for(int k=0;k<len;k++) {
					if(clock()-ti>950) {
						cout<<0<<"\n";
						while(q--)cout<<0<<"\n";
						return 0;
					}
					if(k<j||k>=j+sl[i]) {
						if(s[k]!=t[k]) {
//							cout<<j<<" "<<k<<"\n";
							sbl=0;
							break;
						}
					}
					else if(s[k]!=ss[i][k-j]||st[i][k-j]!=t[k]) {
//						cout<<j<<" "<<k<<"\n";
						sbl=0;
						break;
					}
				}
				if(sbl) {
					bl=sbl;
					break;
				}
			}
//			if(bl)cout<<i<<"\n";
//			else cout<<i<<"!\n";
			ans+=bl;
		}
		cout<<ans<<"\n";
	}
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;
const int p1=508919,mod1=1e9+7,p2=37,mod2=998244353;
int n,q,qz1[N],qz2[N],hsh1[N],hsh2[N];
int poww(int x,int p,int mod) {
	int res=1;
	while(p) {
		if(p&1) res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
string s,t;
unordered_map<int,vector<pair<int,int>>>p;
unordered_map<int,int>cnt;
signed main() {
//	freopen("replace.in","r",stdin);
	freopen("replace1.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	qz1[0]=1,qz2[0]=1;
	for(int i=1;i<=N-5;i++) qz1[i]=qz1[i-1]*p1%mod1,qz2[i]=qz2[i-1]*p2%mod2;
	for(int i=1;i<=n;i++) {
		cin>>s>>t;
		int len=s.size(),fi=-1,ed=-1;
		for(int i=0;i<len;i++) {
			if(i==0) hsh1[i]=s[i]-'a'+1,hsh2[i]=t[i]-'a'+1;
			else hsh1[i]=hsh1[i-1]*p1%mod1,hsh2[i]=hsh2[i-1]*p2%mod2;
			if(s[i]!=t[i]&&fi==-1) fi=i;
			if(s[i]!=t[i]) ed=i;
		}
		int hsh=-1;
		if(fi==-1) fi=0,ed=len-1;
		if(fi==0) hsh=hsh1[ed]*mod2+hsh2[ed];
		else {
			int sh1=(hsh1[ed]-hsh1[fi-1]*qz1[ed-fi+1])*poww(qz1[ed-fi+1],mod1-2,mod1)%mod1;
			int sh2=(hsh2[ed]-hsh2[fi-1]*qz2[ed-fi+1])*poww(qz2[ed-fi+1],mod2-2,mod2)%mod2;
			hsh=sh1*mod2+sh2;
		}
		p[hsh].push_back({fi,len-ed});
		int ssh=hsh1[len-1]*mod2+hsh2[len-1];
		cnt[hsh*fi*(len-ed)*ssh]++;
	}
	for(auto now:p) {
		sort(now.second.begin(),now.second.end());
		int len=unique(now.second.begin(),now.second.end())-now.second.begin();
		if(len!=now.second.size()) now.second[len]={-1,-1};
	}
	for(int i=1;i<=q;i++) {
		cin>>s>>t;
		if(s.size()!=t.size()) {
			cout<<0<<"\n";
			continue;
		}
		int len=s.size(),fi=-1,ed=-1;
		for(int i=0;i<len;i++) {
			if(i==0) hsh1[i]=s[i]-'a'+1,hsh2[i]=t[i]-'a'+1;
			else hsh1[i]=hsh1[i-1]*p1%mod1,hsh2[i]=hsh2[i-1]*p2%mod2;
			if(s[i]!=t[i]&&fi==-1) fi=i;
			if(s[i]!=t[i]) ed=i;
		}
		int hsh=-1;
		if(fi==-1) fi=0,ed=len-1;
		if(fi==0) hsh=hsh1[ed]*mod2+hsh2[ed];
		else {
			int sh1=(hsh1[ed]-hsh1[fi-1]*qz1[ed-fi+1])*poww(qz1[ed-fi+1],mod1-2,mod1)%mod1;
			int sh2=(hsh2[ed]-hsh2[fi-1]*qz2[ed-fi+1])*poww(qz2[ed-fi+1],mod2-2,mod2)%mod2;
			hsh=sh1*mod2+sh2;
		}
		int res=0;
		for(auto now:p[hsh]) {
			if(now.first==-1) break;
			int L=fi-now.first,R=ed+now.second;
			if(L<0||R>len-1) continue;
			int ssh;
			if(L==0) ssh=hsh1[R]*mod2+hsh2[R];
			else {
				int sh1=(hsh1[R]-hsh1[L-1]*qz1[R-L+1])*poww(qz1[R-L+1],mod1-2,mod1)%mod1;
				int sh2=(hsh2[R]-hsh2[L-1]*qz2[R-L+1])*poww(qz2[R-L+1],mod2-2,mod2)%mod2;
				ssh=sh1*mod2+sh2;
			}
			res+=cnt[hsh*now.first*now.second*ssh];
		}
		cout<<res<<"\n";
	}
}
*/
