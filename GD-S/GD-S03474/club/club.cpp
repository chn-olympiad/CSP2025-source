#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=100005,M=205,fin=0x8080808080808080;
int t,n,a[N][5],f[M][M][M],b[N],c[N],B[N],C[N];
inline bool bf1(){
	if(n>200)return 0;
	int r=0;
	for(int i=0;i+i<=n;i++){
		for(int j=0;j+j<=n;j++){
			for(int k=0;k+k<=n;k++){
				if(!i&&!j&&!k)continue;
				f[i][j][k]=max({i?f[i-1][j][k]+a[i+j+k][1]:fin,j?f[i][j-1][k]+a[i+j+k][2]:fin,k?f[i][j][k-1]+a[i+j+k][3]:fin});
				if(i+j+k==n)r=max(r,f[i][j][k]);
			}
		}
	}
	cout<<r<<'\n';
	return 1;
}
inline bool bf2(){
	for(int i=1;i<=n;i++){
		if(a[n][3])return 0;
	}
	int r=0,sum=0;
	for(int i=1;i+i<=n;i++){
		sum+=a[i][1];
	}
	for(int i=1;i+i<=n;i++){
		b[i]=a[i][2]-a[i][1];
	}
	sort(b+1,b+(n>>1)+1);
	reverse(b+1,b+(n>>1)+1);
	for(int i=0;i+i<=n;i++){
		c[i]=sum;
		sum+=b[i+1];
	}
	sum=0;
	for(int i=n;i+i>n;i--){
		sum+=a[i][1];
	}
	for(int i=n;i+i>n;i--){
		B[i]=a[i][2]-a[i][1];
	}
	sort(B+(n>>1)+1,B+n+1);
	reverse(B+(n>>1)+1,B+n+1); 
	for(int i=0;i+i<=n;i++){
		C[i]=sum;
		sum+=B[i+1+(n>>1)];
	}
	reverse(C,C+(n>>1)+1);
	for(int i=0;i+i<=n;i++)r=max(r,C[i]+c[i]);
	cout<<r<<'\n';
	return 1;
}
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	if(bf1())return;
	if(bf2())return;
}
signed main(){
#ifndef XYZ
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}


