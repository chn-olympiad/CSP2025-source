#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,bas=13331,mod=1e9+9;
#define int long long
#define pii pair<int,int>
#define mp make_pair
int n,q,sum[N],sum1[N];
vector<int> hs[N],hs1[N];
int mul[N],nl[N];
map<pii,int> ma;
map<pii,vector<int> > mB;
string s1[N],s2[N];
int fst(int a,int b) {
	int rs=1;
	while(b) {
		if(b&1) rs=rs*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return rs;
}
int calc(int l,int r) {
	int len=r-l+1;
	return (sum[r]-sum[l-1]*mul[len]%mod+mod)%mod;
}
int calc1(int l,int r) {
	int len=r-l+1;
	return (sum1[r]-sum1[l-1]*mul[len]%mod+mod)%mod;
}
void work() {
	for(auto &u:mB) sort(u.second.begin(),u.second.end());
	while(q--) {
		string t1,t2;
		int l,ans=0;
		cin>>t1>>t2;
		l=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int pl=l+1,pr=0;
		int ps=0,ps1=0;
		for(int i=1;i<=l;i++) {
			if(t1[i]=='b') ps=i;
			if(t2[i]=='b') ps1=i;
			if(t1[i]!=t2[i]) {
				pl=min(pl,i);
				pr=max(pr,i);
			}
		}
//		cout<<pl<<" "<<pr<<" "<<ps<<" "<<ps1<<" ";
		for(int i=1;i<=pl;i++) {
			auto &u=mB[mp(pl-i,ps1-ps+1)];
			int ps=upper_bound(u.begin(),u.end(),l-pr)-u.begin();
			if(ps==0) continue;
			ans+=ps;
		}
		cout<<ans<<'\n';
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mul[0]=1;
	for(int i=1;i<N;i++) mul[i]=mul[i-1]*bas%mod;
	nl[N-1]=fst(mul[N-1],mod-2);
	for(int i=N-1;i>=1;i--) nl[i-1]=nl[i]*bas%mod;
	
	cin>>n>>q;
	bool flB=1;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		hs[i].push_back(0);
		hs1[i].push_back(0);
		int fb=0,ct=0,fB=0,ct1=0;
		int ps=0,ps1=0;
		for(int j=1;j<=s1[i].size();j++) {
			hs[i].push_back(0);
			hs1[i].push_back(0);
			hs[i][j]=(hs[i][j-1]*bas%mod+s1[i][j-1]-'a')%mod;
			hs1[i][j]=(hs1[i][j-1]*bas%mod+s2[i][j-1]-'a')%mod;
			
			if(s1[i][j-1]!='b'&&s1[i][j-1]!='a') fb=-1; //B
			else if(s1[i][j-1]=='b') {
				ct++;
				ps=j;
			}
			if(s2[i][j-1]!='b'&&s2[i][j-1]!='a') fB=-1;
			else if(s2[i][j-1]=='b') {
				ct1++;
				ps1=j;
			}
		}
		if(ct==1&&ct1==1&&fb!=-1&&fB!=-1) flB&=1;
		else flB=0; 
//		cout<<ps<<" "<<ps1<<" "<<s1[i].size()-ps1<<endl;
		mB[mp(min(ps,ps1)-1,ps1-ps+1)].push_back(s1[i].size()-max(ps,ps1));
	}
	if(flB) {
//		cout<<"B!\n";
		work();
		return 0;
	} 
//	cout<<"HEY\n";
	for(int op=1;op<=q;op++) {
		string t1,t2;
		int l,ans=0;
		cin>>t1>>t2;
		l=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int pl=l+1,pr=0;
		for(int i=1;i<=l;i++) {
			sum[i]=(sum[i-1]*bas%mod+t1[i]-'a')%mod;
			sum1[i]=(sum1[i-1]*bas%mod+t2[i]-'a')%mod;
			
			if(t1[i]!=t2[i]) {
				pl=min(pl,i);
				pr=max(pr,i);
			}
		}
		
		int len=pr-pl+1;
		for(int i=1;i<=n;i++) {
			int siz=s1[i].size();
			for(int j=0;j<siz;j++) {
				if(j>pl-1||siz-j-len>l-pr||j+len>siz) continue;
//				cout<<pl-j<<" "<<pr+siz-j-len<<endl;
				if(hs[i][siz]==calc(pl-j,pr+siz-j-len)&&hs1[i][siz]==calc1(pl-j,pr+siz-j-len)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
