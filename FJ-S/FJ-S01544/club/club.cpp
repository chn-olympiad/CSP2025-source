#include<bits/stdc++.h>
typedef long long ll;
const int N=205,mod=1e9+7;
using namespace std;
ll a[N][4];
ll f[N/2][N/2][N/2];
ll t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		memset(f,0,sizeof(f));
		ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=min(n-i-j,n/2);k++){
					if((!i)&&(!j)&&(!k)){
						continue;
					}
					int num=i+j+k;
					ll& tmp=f[i][j][k];
					if(i) tmp=max(tmp,f[i-1][j][k]+a[num][1]);
					if(j) tmp=max(tmp,f[i][j-1][k]+a[num][2]);
					if(k) tmp=max(tmp,f[i][j][k-1]+a[num][3]);
					if(num==n) ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
}
