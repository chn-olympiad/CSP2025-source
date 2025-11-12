#include<bits/stdc++.h>
#define int long long
#define ll long long
#define bint __int128
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define debug(x) cout<<#x<<" = "<<x<<endl
using namespace std;
const ll mod=998244353;
inline ll fpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
	return res;
}
const int N=1e5+5;
int n,m,T;
ll a[N][3];
int pos[N];
int cnt[3];
int del[N],idx;
void solve(){
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=0;
	ll res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		pos[i]=0;
		if(a[i][1]>a[i][pos[i]])pos[i]=1;
		if(a[i][2]>a[i][pos[i]])pos[i]=2;
		cnt[pos[i]]++;
		res+=a[i][pos[i]];
	}
	for(int j=0;j<3;j++)if(cnt[j]*2>n){
		idx=0;
		for(int i=1;i<=n;i++){
			if(pos[i]==j)
				del[++idx]=a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]);
		}
		sort(del+1,del+1+idx);
		for(int i=1;i<=idx-(n/2);i++)res-=del[i];
	}
	cout<<res<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
//  每个人按照最优的选之后贪心调整就行了把
//  感觉很 ez
