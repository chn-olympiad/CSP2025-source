#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define Fr(i,a,b) for(int i=a;i>=b;i--)
const int N=505,mod=998244353;
int n,m,c[N],a[N],p[N],b[N],g,r,ans;
string s;
void dfs(int k){
    if(k>n){
		g=r=0;
		fr(i,1,n){
			if(c[p[i]]<=g) g++;
			else if(a[i]) r++;
			else g++;
		} if(r>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		} return;
	} fr(i,1,n) if(!b[i])
	    b[i]=1,p[k]=i,dfs(k+1),b[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>s;
	fr(i,1,n) cin>>c[i];
	fr(i,1,n) a[i]=s[i-1]-'0';
	dfs(1); cout<<ans;
	return 0;
}
