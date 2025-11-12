#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
vector<int>num[5*N];
int f[N][2],n,k,a[N],s[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	num[0].push_back(0);
	for(int i=1;i<=n;i++){
		num[s[i]].push_back(i);
	}
	int x=0;
	for(int i=1;i<=n;i++){
		f[i][0]=x;
		int t=s[i]^k;
		int mx=-1;
		for(auto y:num[t]){
			if(y<i) mx=max(mx,max(f[y][0],f[y][1]));
		}
		f[i][1]=mx+1;
		x=max(x,max(f[i][1],f[i][0]));
	}
	int ans=-1;
	for(int i=1;i<=n;i++) ans=max(ans,max(f[i][0],f[i][1]));
	cout<<ans;
	return 0;
}
