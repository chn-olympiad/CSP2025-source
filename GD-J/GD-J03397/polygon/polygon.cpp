#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int n,a[5001],f[5003][4],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
//	cout<<sizeof(f);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++){	
			(ans+=f[j][3]+f[j][2])%=mod;
		}	
		for(int j=5001;j>=1;j--){
			if(j+a[i]>5000){
				(f[5001][3]+=f[j][2]+f[j][3])%=mod;
				(f[5001][2]+=f[j][1])%mod;
			//	f[i+1][5001][1]+=1;
			}else{
				(f[j+a[i]][3]+=f[j][2]+f[j][3])%=mod;
				(f[j+a[i]][2]+=f[j][1])%=mod;
				//cout<<i<<" "<<j<<" :"<<f[j][3]<<" "<<f[j][2]<<endl;
				//f[i+1][j+a[i]][1]+=1;
			}
		}
		(f[a[i]][1]+=1)%=mod;
	}
	cout<<ans;
}
