#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
const int p=998244353;
bool Mbe;

int a[N],c[N],cnt[N];
int f[(1<<18)+1][20];
int solveS(int n,int m){
	f[0][0]=1;
	for(int i=0;i<((1<<n)-1);i++){
		int now=0;
		for(int j=0;j<n;j++) if(i&(1<<j)) now++;
		for(int j=0;j<=now;j++){
			for(int k=0;k<n;k++){
				if(i&(1<<k)) continue;
				if(c[k+1]>now-j&&a[now+1]==1){
					f[i+(1<<k)][j+1]=(f[i+(1<<k)][j+1]+f[i][j])%p;
				}else{
					f[i+(1<<k)][j]=(f[i+(1<<k)][j]+f[i][j])%p;
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++){
		ans=(ans+f[(1<<n)-1][i])%p;
		//cout<<f[(1<<n)-1][i]<<"\n";
	}
	return ans;
}

void fake_main(){
	int n,m; cin>>n>>m; int flagA=1;
	for(int i=1;i<=n;i++){
		char ch; cin>>ch;
		a[i]=ch-'0'; if(a[i]==0) flagA=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cnt[c[i]]++;
	}
	
	if(n<=18){
		cout<<solveS(n,m)<<"\n";
		return;
	}
}

bool Med;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cerr<<fabs(&Med-&Mbe)/1028576.0<<"MB\n";
	int t; t=1;
	while(t--) fake_main();
	cerr<<clock()*1.0/CLOCKS_PER_SEC*1000.0<<"ms\n";
}

