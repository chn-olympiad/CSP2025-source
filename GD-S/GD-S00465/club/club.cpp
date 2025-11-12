#include<bits/stdc++.h>
using namespace std;
//const int N=1e5+10;
const int N=210;
const int INF=0x3f3f3f3f;
const int M=1e5+10;
int a[4][M];
int f[N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		bool b2=0,b3=0;
		for(int i=1;i<=n;++i){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			b2|=a[1][i];
			b3|=a[2][i];
		}
		if(n>200){
			if(b2==0&&b3==0){
				sort(a[0]+1,a[0]+1+n);
				long long ans=0;
				for(int i=n;i>n/2;--i){
					ans+=a[0][i];
				}
				cout<<ans<<'\n';
			}
			continue;
		}
		for(int i=n;i>=0;--i){
			for(int j=n;j>=0;--j){
				f[i][j]=-INF;
			}
		}
		f[0][0]=0;
		int ans=0;
		for(int k=1;k<=n;++k){
			for(int i=n/2;i>=0;--i){
				for(int j=n/2;j>=0;--j){//现合法 
					f[i+1][j]=max(f[i+1][j],f[i][j]+a[0][k]);
					f[i][j+1]=max(f[i][j+1],f[i][j]+a[1][k]);
					f[i][j]+=a[2][k];
				}
			}
		}
		for(int i=n/2;i>=0;--i)
			for(int j=n/2;i+j>=n/2;--j)//现合法 
				ans=max(ans,f[i][j]);
		cout<<ans<<'\n';
	}
	return 0;
}
