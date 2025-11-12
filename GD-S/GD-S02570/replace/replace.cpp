#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5,M=5e6+5;
const ll base=114514,MOD=1234567891;
string ss[N][2];
ll a[N][6];
bool vis[N];
ll b[M];
struct node
{
	ll h[M];
	void init(string s)
	{
		int len=s.length();
		for(int i=1;i<=len;i++) h[i]=(h[i-1]*base%MOD+s[i-1]-'a')%MOD;
	}
	ll cal(int l,int r)
	{
		return (h[r]-h[l-1]*b[r-l+1]%MOD+MOD)%MOD;
	}
}hs;
int n,q;
//map<int,int> mp;
//bool check()
//{
//	for(int i=1;i<=n;i++){
//		int slen=ss[i][0].length(),tlen=ss[i][1].length();
//		int cnt1=0,cnt2=0;
//		for(int j=0;j<slen;j++) if(ss[i][0][j]=='b') cnt1++;
//		for(int j=0;j<tlen;j++) if(ss[i][1][j]=='b') cnt2++;
//		if(cnt1!=1||cnt2!=1) {
//			return false;
//		}
//	}
//	return true;
//}
//void work()
//{
//	for(int i=1;i<=n;i++){
//		int slen=ss[i][0].length(),tlen=ss[i][1].length();
//		int l=-1,r=-1;
//		for(int j=0;j<slen;j++) if(ss[i][0][j]=='b') l=i;
//		for(int j=0;j<tlen;j++) if(ss[i][1][j]=='b') r=i;
//		mp[r-l]++;	
//	}
//	while(q--)
//	{
//		string s,t;cin>>s>>t;
//		int slen=s.length(),tlen=t.length();
//		if(slen!=tlen) {cout<<"0\n";continue;}
//		int l=-1,r=-1;
//		for(int i=0;i<slen;i++) if(s[i]=='b') l=i;
//		for(int i=0;i<tlen;i++) if(t[i]=='b') r=i;
//		cout<<mp[r-l]<<'\n';
//	}
//}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	b[0]=1;
	for(int i=1;i<M;i++) b[i]=b[i-1]*base%MOD;
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		ss[i][0]=s,ss[i][1]=t;
		int len=s.length();
		int l=-1,r=-1;
		for(int i=0;i<len;i++) {
			if(s[i]!=t[i]){
				if(l==-1) l=i+1;
				r=i+1;
			}
		}
		if(l!=-1){
			hs.init(s);a[i][0]=hs.cal(1,len),a[i][1]=hs.cal(l,r);
			hs.init(t);a[i][2]=hs.cal(l,r);
			a[i][3]=l,a[i][4]=r,a[i][5]=len;
			vis[i]=0;
		}
		else {
			hs.init(s);a[i][0]=hs.cal(1,len),a[i][1]=len;
			vis[i]=1;
		}
	}
//	if(check()){
//		work();
//		return 0;
//	}
	while(q--)
	{
		string s,t;cin>>s>>t;
		int len=s.length();
		if(len!=(int)t.length()) {cout<<0<<'\n';continue;}
		int l=-1,r=-1;
		for(int i=0;i<len;i++) {
			if(s[i]!=t[i]){
				if(l==-1) l=i+1;
				r=i+1;
			}
		}
		int ans=0;
		if(l!=-1){
			int y,z;
			hs.init(t);z=hs.cal(l,r);
			hs.init(s);y=hs.cal(l,r);
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				int L=l-a[i][3]+1,R=r+a[i][5]-a[i][4];
				if(L<1||R>len) continue;
				if(y==a[i][1]&&z==a[i][2]&&hs.cal(L,R)==a[i][0]) ans++;
			}
		}
		else {
			hs.init(s);
			for(int i=1;i<=n;i++){
				if(!vis[i]) continue;
				for(int j=1;j<=len-a[i][1]+1;j++){
					if(a[i][0]==hs.cal(j,j+a[i][1]-1)) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
