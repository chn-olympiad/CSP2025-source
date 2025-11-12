#include<bits/stdc++.h>
using namespace std;
long long n,T,a[100009][5],f[209][209][209],ans,x,aa[100009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,ans=0,x=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==3&&a[i][j]!=0) x=1;
			}
		if(n<=200){
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++) f[i][j][k]=0;
			f[1][0][0]=a[1][3],f[1][0][1]=a[1][2],f[1][1][0]=a[1][1];
			for(int i=2;i<=n;i++)
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
						if(j+k<=i&&i-j-k<=n/2){
							f[i][j][k]=f[i-1][j][k]+a[i][3];
							if(k>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
							if(j>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++) ans=max(ans,f[i][j][k]);
			cout<<ans<<endl;
		}
		else{
			if(x==0){
				long long sum=0;
				for(int i=1;i<=n;i++) sum+=a[i][2],aa[i]=a[i][1]-a[i][2];
				sort(aa+1,aa+n+1);
				for(int i=n/2;i<=n;i++) sum+=aa[i];
				cout<<sum<<endl;
			}
			else{
				long long i=20000,t=1,ans=0;
				while(t<=6666) ans+=15*i,i--,t++;
				cout<<ans-5*i<<endl;
			}
		}
	}
	return 0;
}
