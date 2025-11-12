#include<bits/stdc++.h>
using namespace std;
long long ss,n,m,l,a[1000007],a1,g[507][107][107],f[507][107][107],ans,jc[1000007],ny[1000007],n1,m1,l1;
long long bo[1000007];
const long long k=998244353;
string st;
long long ksm(long long x,long long y){
	n1=x,m1=y,l1=1;
	while(m1){
		if(m1&1)l1=l1*n1%k;
		n1=n1*n1%k;
		m1>>=1;
	}
	return l1;
}
long long zh(int x,int y){return jc[x]*ny[y]%k*ny[x-y]%k;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>st;jc[0]=ny[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%k;
	ny[n]=ksm(jc[n],k-2);
	for(int i=n-1;i>=0;i--)ny[i]=ny[i+1]*(i+1)%k; 
	long long s=0;
	for(int i=1;i<=n;i++){
		if(st[i-1]=='0')++s;
		else bo[s]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]--;
	}
	sort(a+1,a+n+1);ss=bo[0];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int o=0;o<=n;o++){
				for(int u=0;u<=n;u++){
					g[j][o][u]=f[j][o][u];
					
					f[j][o][u]=0;
				}
			}
		}
		if(a[i-1]<a[i]){
			for(int t=a[i-1]+1;t<=a[i];t++){
				ss+=bo[t];
				for(int j=0;j<=n;j++){
					for(int o=0;o<=n;o++){
						for(int u=0;u<=n;u++){
							
							for(int x=0;x<=min(bo[t],u+0ll);x++){
								
								f[j][o+x][u-x]=(f[j][o+x][u-x]+g[j][o][u]*zh(bo[t],x)%k*zh(u,x)%k*jc[x]%k)%k;
							}
						}
					}
				}
			}
			for(int j=0;j<=n;j++){
				for(int o=0;o<=n;o++){
					for(int u=0;u<=n;u++){
						g[j][o][u]=f[j][o][u];
						f[j][o][u]=0;
					}
				}
			}
		}
		
		for(int j=0;j<=n;j++){
			for(int o=0;o<=n;o++){
				for(int u=0;u<=n;u++){
					if(ss>j)f[j+1][o][u]=(f[j+1][o][u]+g[j][o][u]*(ss-j))%k;
					f[j][o+1][u]=(f[j][o+1][u]+g[j][o][u]*(s-o))%k;
					//if(i==2&&j==0&&o==0&&u==1)cout<<g[j][o][u]<<'\n';
					f[j][o][u+1]=(f[j][o][u+1]+g[j][o][u])%k;
					
				}
			}
		}
	}
	for(int j=m;j<=n;j++){
		for(int o=0;o<=n-m;o++){
			ans+=f[j][o][0];
			//if(f[j][o][0])cout<<j<<' '<<o<<' '<<f[j][o][0]<<'\n';
		}
	}
	cout<<ans%k;
}
