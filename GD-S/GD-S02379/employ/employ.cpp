#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m,a[555],c[555],f[555][555],g[555][555],C[555][555];
ll A[555][555];
string kao_shi_tai_jian_dan_ke_yi_ti_qian_li_chang_ma;
void add(int&x,ll y){
	x=(x+y)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>kao_shi_tai_jian_dan_ke_yi_ti_qian_li_chang_ma;
	for(int i=1,j;i<=n;i++) scanf("%d",&j),c[j]++,a[i]=kao_shi_tai_jian_dan_ke_yi_ti_qian_li_chang_ma[i-1]-'0';
	for(int i=0;i<=n;i++){
		A[i][0]=1;
		for(int j=1;j<=i;j++) A[i][j]=A[i][j-1]*(i-j+1)%mod;
	}
	for(int i=0;i<=n;i++) for(int j=C[i][0]=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(!f[j][k]) continue;
				if(a[i]) add(g[j][k+1],f[j][k]);
				else for(int l=0;l<=c[j+1]-c[j];l++) for(int o:{0,1}) add(g[j+1][k-l+o],f[j][k]*A[c[j+1]-c[j]][l+!o]%mod*C[k][l]);
				for(int l=0;l<=c[j+1]-c[j];l++) add(g[j+1][k-l],f[j][k]*A[c[j+1]-c[j]][l]%mod*max(c[j]-(i-k-1),0)%mod*C[k][l]);
			}
		}
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[j][k]=g[j][k],g[j][k]=0;
	}
	int ready_to_AFO=0;
	for(int i=0;i<=n-m;i++) for(int j=0;j<=n;j++) add(ready_to_AFO,f[i][j]*A[c[n]-c[i]][j]);
	cout<<ready_to_AFO;
	return 0;
}
