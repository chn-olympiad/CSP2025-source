#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int base=133,mod=1e9+901;
const int maxn=1e5+10;
pi bl(string a,string b){
	int le=a.size();
	int l=0,r=0,x=0;
	bool bo=0;
	for(int i=0;i<le;i++){
		if(a[i]!=b[i]){
			if(!bo)l=r=i;
			else r+=x+1;
			x=0;
			bo=1;
		}
		else if(bo)x++;
	}
	return {l,r};
}
string a[maxn],b[maxn];
string x[maxn],y[maxn],y1[maxn],z[maxn];
int hashx[maxn],hashz[maxn];
int hashx1[maxn],hashz1[maxn];
int longx[maxn],longz[maxn];
int n,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int asdf=1;asdf<=n;asdf++){
		cin>>a[asdf]>>b[asdf];
		int len=a[asdf].size();
		auto xx=bl(a[asdf],b[asdf]);
		int l=xx.first,r=xx.second;
		for(int i=0;i<l;i++)x[asdf]+=a[asdf][i];
		for(int i=0,j=l-1;i<j;i++,j--)swap(x[asdf][i],x[asdf][j]);
		for(int i=0;i<l;i++)hashx[asdf]=(hashx[asdf]*base%mod+x[asdf][i])%mod;
		for(int i=l;i<=r;i++)y[asdf]+=a[asdf][i],y1[asdf]+=b[asdf][i];
		for(int i=r+1;i<len;i++)z[asdf]+=a[asdf][i];
		for(int i=r+1;i<len;i++){
			hashz[asdf]=(hashz[asdf]*base%mod+z[asdf][i])%mod;
			longz[asdf]++;
		}
		longx[asdf]=l;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		auto xx=bl(t1,t2);
		int l=xx.first,r=xx.second;
		string s,s1;
		for(int i=l;i<=r;i++)s+=t1[i],s1+=t2[i];
		for(int i=l-1;i>=0;i--){
			int id=l-1-i;
			hashx1[id]=(hashx1[id-1]*base%mod+t1[i])%mod;
		}
		for(int i=r+1;i<len;i++){
			int id=i-r-1;
			hashz1[id]=(hashz1[id-1]*base%mod+t1[i])%mod;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s==y[i]&&s1==y1[i]&&hashx1[longx[i]-1]==hashx[i]&&hashz1[longz[i]-1]==hashz[i])ans++;
		}
		cout<<ans<<'\n';
	}
}
