#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=1e5+5;
int n,c[4],a[N][4],sum[4];struct Node{int mx,pmx;}p[4][N];
void solve(){
	for(int i=1;i<=3;i++)c[i]=sum[i]=0;
	cin>>n;for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if     (a[i][1]>=a[i][2] and a[i][1]>=a[i][3])p[1][++c[1]]={a[i][1],max(a[i][2],a[i][3])};
		else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3])p[2][++c[2]]={a[i][2],max(a[i][1],a[i][3])};
		else                                        p[3][++c[3]]={a[i][3],max(a[i][1],a[i][2])};
	}
	for(int j=1;j<=3;j++){
		sort(p[j]+1,p[j]+1+c[j],[](Node n1,Node n2){return n1.mx+n2.pmx>n1.pmx+n2.mx;});
		for(int i=1;i<=c[j];i++)sum[j]+=(i<=n/2)?p[j][i].mx:p[j][i].pmx;
	}
	cout<<sum[1]+sum[2]+sum[3]<<"\n";
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t;cin>>t;while(t--)solve();return 0;
}