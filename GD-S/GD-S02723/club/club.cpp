#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5,M=205;
int t,n,ans,a[N][5],b[N],f[M][M][M];
bool A;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;ans=A=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])A=1;
		}
		if(!A){
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n;i>=(n>>1);i--)
				ans+=b[i];
		}else{
			for(int i=0;i<=n;i++)
				for(int j=0;j<=(n>>1);j++)
					for(int k=0;k<=(n>>1);k++)
						f[i][j][k]=-1;
			f[0][0][0]=0;
			for(int i=1;i<=n;i++)
				for(int j=min(i,n>>1);~j;j--)
					for(int k=min(i-j,n>>1);~k;k--){
						if(~f[i-1][j][k])f[i][j][k]=f[i-1][j][k]+a[i][3];
						if(j&&(~f[i-1][j-1][k]))f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k&&(~f[i-1][j][k-1]))f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
					}
			for(int i=0;i<=(n>>1);i++)
				for(int j=(n>>1)-i;j<=(n>>1);j++)
					ans=max(ans,f[n][i][j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
