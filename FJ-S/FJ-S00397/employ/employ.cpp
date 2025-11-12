#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int MAXN=510,mod=998244353;
string s;
ll ans=0;
int c[MAXN];
int n,m;
bool l[MAXN];
ll jc(int x){
	int res=1;
	fo(i,1,x){
		res*=i;
	}
	return res;
}
void dfs(int x,int d,int e) {
//	cout<<"dfs "<<x<<" day "<<d<<'\n';
	if(s[d-1]=='1') {
//		cout<<"pass "<<d-e-1<<' '<<c[x]<<'\n';
		if((d-e-1)<c[x]) {
//			cout<<"emp\n";
			e++;
		}
	}
	if(d==n) {
//		cout<<"emp end "<<e<<"\n";
		if(e>=m) {
			ans++;
//			cout<<"ans++\n";
		}
		return;
	}
	if(e==m){
		ans+=jc(n-d);
		return;
	}
	fo(i,1,n) {
		if(l[i]==0) {
			l[i]=1;
			dfs(i,d+1,e);
			l[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int t=0;
//	fo(i,0,n-1){
//		t+=(s[i]=='1'?1:0);
//	}
//	if(t<m){
//		cout<<0;
//		return 0;
//	}
	fo(i,1,n) {
		cin>>c[i];
	}
	fo(i,1,n) {
		l[i]=1;
		dfs(i,1,0);
		l[i]=0;
	}
	cout<<ans%mod;
	return 0;
}
