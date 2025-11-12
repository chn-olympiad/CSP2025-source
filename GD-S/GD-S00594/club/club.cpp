#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
using ll = long long;
int n;
int a[MAXN][4],cho[MAXN];
int cnt[4];
void solve(){
	cin>>n;
	ll ans = 0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		for(int c=1;c<=3;c++)cin>>a[i][c];
		int pos = 1;
		for(int c=1;c<=3;c++){
			if(a[i][c] > a[i][pos])pos=c;
		}
		ans += a[i][pos];
		cnt[pos]++;
		cho[i]=pos;
	}
	int pos = 1;
	for(int i=1;i<=3;i++)if(cnt[i]>cnt[pos])pos=i;
	if(cnt[pos]<=n/2){
		cout<<ans<<"\n";
		return;
	}
	vector<int> d;
	for(int i=1;i<=n;i++){
		if(cho[i]!=pos)continue;
		int mxv = 0;
		for(int j=1;j<=3;j++){
			if(j!=pos)mxv = max(mxv,a[i][j]);
		}
		d.push_back(a[i][pos]-mxv);
	}
	sort(d.begin(),d.end());
	int qwq = cnt[pos]-n/2;
	for(int i=0;i<qwq;i++){
		ans -= d[i];
	}
	cout<<ans<<"\n";
}
int main(){
#ifndef SVK
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T;cin>>T; while(T--)solve();
	return 0;
}

