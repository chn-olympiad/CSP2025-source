#include<bits/stdc++.h>
#define MX 505
#define int long long
//congratulations!
//wait to test
//now goto T3
//now back
//maybe 100+[80,100]+[50,80]+100
//lowest 330 win
//but if many know how to solve T3
//aaaaaa why stringggg
using namespace std;
const int mod=998244353;
int read();int Read();
int n,m,p,np,a[MX],b[MX],f[MX][MX],frc[MX];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();frc[0]=1;
	for(int i=1;i<=n;i++) frc[i]=frc[i-1]*i%mod;
	for(int i=1;i<=n;i++) a[i]=Read();
	//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	//cout<<'\n';
	for(int i=1;i<=n;i++) b[read()]++;
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	//for(int i=0;i<=n;i++) cout<<b[i]<<' ';
	//cout<<'\n';
	f[0][0]=1;int o=0;
	for(int i=1;i<=n;i++){o^=1;
		if(a[i]){
			for(int j=n-1;j>=0;j--) for(int k=np;k>=0;k--){
				int w=f[j][k];
				f[j+1][k]=(f[j+1][k]+w*(b[j]-(j-p)-k))%mod;
				f[j][k+1]=(f[j][k+1]+w*(b[j]-(j-p)-k))%mod;
			}
			np++;
		}else{
			p++;
			for(int j=n-1;j>=0;j--) for(int k=0;k<=n;k++){
				f[j+1][k]=f[j][k];f[j][k]=0;}
		}
		/*for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++)
				cout<<f[o][j][k]<<' ';
			cout<<'\n';
		}
		cout<<'\n';*/
	}
	for(int i=n;i>=p;i--){
		int I=np-(i-p),cnt=0;
		//cout<<I<<'\n';
		for(int j=0,ml=1;j<=I;j++,ml=mod-ml){
			int w=f[i][j]*frc[n-(i+j-p)]%mod;
			cnt=(cnt+ml*w)%mod;
		}
		//cout<<i<<' '<<cnt<<'\n';
		f[i][0]=cnt;
	}
	int res=0;
	for(int i=0;i<=n-m;i++) res=(res+f[i][0])%mod;
	printf("%lld\n",res);
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}
int Read(){
	char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();}
	return (Cr-'0');
}