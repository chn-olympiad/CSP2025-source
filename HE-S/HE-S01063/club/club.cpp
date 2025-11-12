#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100010][4],b[100010];
int maxn[100010];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	int ans=0;
	bool f=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][3]!=0)f=0;
		maxn[i]=max(a[i][1],max(a[i][2],a[i][3]));
	}
	if(f){
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ans+=maxn[i];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
