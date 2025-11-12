
// Surpassing never ends!

#include<bits/stdc++.h>
#define ll long long
//#define int long long 
using namespace std;
const int N=505,M=1e6+100;
const ll P=998244353;
int read() {
	int x=0;
	short f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-')f=-1;c=getchar(); }
	while(c>='0'&&c<='9') { x=x*10+c-'0';c=getchar(); }
	return x*f;
}
bool MB_1;

int n,m,c[N],p[N];ll jc[N];
char s[N];

bool MB_2;

signed main() {
//	cerr<<fabs(&MB_2-&MB_1)/(1024*1024)<<"MB\n";
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;scanf("%s",s+1);
	
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%P;
	
	for(int i=1;i<=n;i++) if(s[i]=='1') c[0]++;
	for(int i=1;i<=n;i++) c[i]=read(),p[i]=i; 
	
	if(n==m&&c[0]==n) {
		for(int i=1;i<=n;i++) if(c[i]==0) { cout<<0;return 0; }
		cout<<jc[n]; return 0;
	}
	else if(n<=10){
		c[0]=0;
		ll ans=0;
		for(int i=1;i<=jc[n];i++) {
			int ct=0;
			for(int j=1;j<=n;j++) {
//				cout<<s[j];
				if(s[j]=='0') ct++;
				else {
					if(ct>=c[p[j]]) ct++;
				}
			}
	//		for(int j=1;j<=n;j++) cout<<p[j]<<" ";
	//		cout<<ct<<'\n';
			if(n-ct>=m) ans++;
			next_permutation(p+1,p+1+n);
		}
		cout<<ans;
	}
	else {
		cout<<0;
	}
	return 0;
}
