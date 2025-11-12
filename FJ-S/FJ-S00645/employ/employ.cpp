#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505,mo=998244353;
int n,m,cnt=0,ans=1,res=0,r[maxn];
string s;
map<int,int> d;
int jc[maxn],p[maxn],c[maxn];
bool bo=0;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>s;
	jc[1]=1;
	for(int i=2; i<=n; i++) {
		jc[i]=jc[i-1]*i;
	}
	for(int i=1; i<=n; i++) {
		p[i]=s[i-1]-'0';
		if(p[i]) {
			cnt++;
		}
		cin>>c[i];
		d[c[i]]++;
	}
	if(cnt<m) {
		cout<<0;
		return 0; 
	}
	sort(c+1,c+1+n);
	cnt=0;
	for(int i=1; i<=n; i++) {
		if(p[i]&&c[i]>cnt) r[++res]=c[i],bo=1;
		else if(c[i]!=0) cnt++;
	}
	if(bo==0) {
		ans=0;
	} else {
		for(int i=1; i<=res; i++) {
			if(r[i]<=cnt+1) {
				ans*=jc[d[r[i]]];
			} else {
				ans*=jc[r[i];
			}
		}
	}
	cout<<ans%mo<<endl;
	return 0;
}


