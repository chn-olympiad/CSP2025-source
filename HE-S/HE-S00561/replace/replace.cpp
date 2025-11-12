#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
typedef pair<int,int> pai;
const int N=2e5+10;
const int M=5e6+10;
const int mod=998244353;
const int bas=1331;
int n,q,sum;
int s[N][2],len,pw[N];
char tmp[N],ta[N],tb[N];

map<pai,int> mp;

//int tot;
//struct node{
//	int p,len,d,id;
//}c[N];

//vector<int> d;

int a[N],b[N];

int calc(int l,int r,int *w) {
	return (w[r]-w[l-1]*pw[r-l+1]%mod+mod)%mod;
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	
	pw[0]=1;
	for(int i=1;i<=N-10;i++) pw[i]=pw[i-1]*bas%mod;
	
	for(int i=1;i<=n;i++) {
		int res=0;
//		int p1=0,p2=0;
		cin>>(tmp+1);
		len=strlen(tmp+1);
		sum+=len;
		for(int j=1;j<=len;j++) {
			res=(res*bas%mod+tmp[j]-'a'+1)%mod;
//			if(tmp[j]=='b') p1=j;
		}
		s[i][0]=res;
		
		res=0;
		cin>>(tmp+1);
		for(int j=1;j<=len;j++) {
			res=(res*bas%mod+tmp[j]-'a'+1)%mod;
//			if(tmp[j]=='b') p2=j;
		}
		s[i][1]=res;
		
//		cout<<s[i][0]<<' '<<s[i][1]<<'\n';
		
		mp[{s[i][0],s[i][1]}]=1;
		
//		c[++tot]={p1,len,p1-p2,0};
	}
//	if(n<=1000&&sum<=2000) {
		while(q--) {
			cin>>(ta+1);
			cin>>(tb+1);
			len=strlen(ta+1);
			if(len!=(int)strlen(tb+1)) {
				cout<<0<<'\n';
				continue;
			}
			int L=0,R=0;
			for(int i=1;i<=len;i++) {
				a[i]=(a[i-1]*bas%mod+ta[i]-'a'+1)%mod;
				b[i]=(b[i-1]*bas%mod+tb[i]-'a'+1)%mod;
				if(ta[i]!=tb[i]) {
					if(!L) L=i;
					R=i;
				}
			}
	//		cout<<L<<' '<<R<<' '<<a[4]<<' '<<b[4]<<' '<<a[1]<<' '<<b[1]<<'\n';
			
			int res=0;
			for(int l=L;l>=1;l--) {
				for(int r=R;r<=len;r++) {
					int x=calc(l,r,a),y=calc(l,r,b);
					if(mp[{x,y}]) {
	//					cout<<":"<<l<<' '<<r<<' '<<x<<' '<<y<<'\n';
						res++;
					}
				}
			}
			cout<<res<<'\n';
		}
//	}
//	else {
//		while(q--) {
//			cin>>(ta+1);
//			cin>>(tb+1);
//			len=strlen(ta+1);
//			if(len!=(int)strlen(tb+1)) {
//				cout<<0<<'\n';
//				continue;
//			}
//			int p1=0,p2=0;
//			for(int i=1;i<=len;i++) {
//				if(ta[i]=='b') p1=i;
//				if(tb[i]=='b') p2=i;
//			}
//			c[++tot]={p1,len,}
//		}
//	}
	
	return 0;
}
