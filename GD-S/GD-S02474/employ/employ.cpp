#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,cnt=0;
string s;
int a[200007],b[200007],jc[200007],c[200007];
void dfs(int x,int y)
{
	if(y==m){
//		cout<<y<<":";
//		for(int i=1;i<=n;++i) cout<<c[i]<<" ";
//		cout<<"\n";
		cnt+=jc[n-x+1];
		cnt%=mod;
		return;
	}else if(x==n+1) return;
	int d=x-y-1;
	for(int i=1;i<=n;++i){
		if(b[i]) continue;
		if(s[x-1]=='0'){
			b[i]=1,c[x]=i;
			dfs(x+1,y);
			b[i]=0;
		}else{
			b[i]=1,c[x]=i;
			if(a[i]<=d) dfs(x+1,y);
			else dfs(x+1,y+1);
			b[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=500;++i){
		jc[i]=(jc[i-1]*i)%mod;
	}
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int c=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='1') c++;
	}
	if(m>c){
		cout<<0;
		return 0;
	}
	if(m==n){
		int cc=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0) cc++;
		}
		if(cc>0) cout<<0;
		else if(cc==0&&c==n) cout<<jc[n];
		else cout<<0;
		return 0;
	}else if(c==n){
		cout<<jc[n];
		return 0;
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
}
