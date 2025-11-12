#include <iostream>
using namespace std;
const int NR=505,M=998244353;
int n,m,s[NR],c[NR],cnt=0,f[19][1<<18],bnt=0;
char t;
int qp(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		s[i]=t-'0';
		cnt+=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)bnt++;
	}
	if(n<=18){
		f[0][0]=1;
		for(int j=0;j<(1<<n)-1;j++){
			int cnt=0;
			for(int l=1;l<=n;l++){
				if(j&(1<<l-1)){
					cnt++;
				}
			}
			for(int l=1;l<=n;l++){
				if(!(j&(1<<l-1))){
					int h=j+(1<<l-1);
					if(!s[cnt+1]){
						for(int m=0;m<n;m++){
							f[m+1][h]=(f[m+1][h]+f[m][j])%M;
						}
					}else{
						for(int m=0;m<=n;m++){
							if(c[l]<=m&&f[m][j]){
								f[m+1][h]=(f[m+1][h]+f[m][j])%M;
							}
							if(c[l]>m&&f[m][j])
								f[m][h]=(f[m][h]+f[m][j])%M;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++){
			ans=(ans+f[i][(1<<n)-1])%M;
		}
		cout<<ans;
	}else if(m==n){
		if(cnt!=n) {
			cout<<0;
		}else if(bnt){
			cout<<"0";
		}else{
			long long ans=1;
			for(int i=1;i<=n;i++)ans=(ans*1ll*i)%M;
			cout<<ans;
		}
	}else{
		
	}
	return 0;
}