#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=600;
//const int M=
const ll mod=998244353;
ll ttg;
ll jc(int u){
	ll x=1;
	fo(i,1,u){
		x*=i;
		x%=mod;
	}
	return x;
}
int n,m;
int bo[N];
int c[N];
string s;
bool vis[N];
bool vct[N];
int b[N],bj[N];
bool cmp(int a1,int a2){
	return a1<a2;
}
ll ans=0;
void dfs(int ceng,int sum){
	if(ceng==n+1&&sum>=m){
		ans++;
		return;
	}
	if(ceng==n+1)return;
	fo(i,1,n){
		if(vis[i]==0){
			vis[i]=1;
			if(bo[ceng]==1&&ceng-sum<c[i])sum++;
			dfs(ceng+1,sum);
			vis[i]=0;
			if(bo[ceng]==1&&ceng-sum<c[i])sum--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int lent=s.size();
	int flag=1;
	fo(i,0,lent){
		bo[i+1]=s[i]-'0';
	}
	fo(i,1,n)cin>>c[i];
	sort(c+1,c+n+1,cmp);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

