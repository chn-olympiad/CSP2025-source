#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e6+5,mod=998244353,INF=2e9;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
int a[N][4];
void solve(){
	vector<int>G[4];
	int cnt[4]={0,0,0};
	int n;
	cin>>n;
	rep(i,1,n){
		rep(k,0,2){
			cin>>a[i][k];
		}
	}
	int res=0;
	rep(i,1,n){
		int maxn=0,pos=0;
		rep(k,0,2){
			if(maxn<a[i][k]){
				maxn=max(maxn,a[i][k]);
				pos=k;
			}
		}
		res+=maxn;
		cnt[pos]++;
		G[pos].push_back(i);
	}
	if((cnt[0]<=(n/2))&&(cnt[1]<=(n/2))&&(cnt[2]<=(n/2))){
		cout<<res<<endl;
	}else{
		int now=0;
		rep(i,0,2){
			if(cnt[i]>n/2){
				now=i;
			}
		}
		vector<int>P;
		for(auto i:G[now]){
			int maxn=0,pos=0;
			rep(k,0,2){
				if(maxn<a[i][k]){
					maxn=max(maxn,a[i][k]);
					pos=k;
				}
			}
			int qaq=INF;
			rep(k,0,2){
				if(pos!=k)
					qaq=min(qaq,maxn-a[i][k]);
			}
			P.push_back(qaq);
		}
		sort(P.begin(),P.end());
		rep(i,0,cnt[now]-(n/2)-1){
			res-=P[i];
		}
		cout<<res<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	rep(i,1,T){
		solve();
	}
	return 0;
}