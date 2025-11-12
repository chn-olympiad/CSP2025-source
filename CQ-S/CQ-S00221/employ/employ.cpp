#include<bits/stdc++.h>
using namespace std;
const int N=510;
char s[N];
const int p=998244353;
int c[N],a[N],f[19][19][1<<18];
void chmod(int &x,int y){x+=y;if(x>=p)x-=p;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<(1<<n);k++){
				if(!f[i][j][k])continue;
				for(int l=0;l<n;l++){
					if(k&(1<<l))continue;
					if(s[i+1]=='1'&&c[l+1]>j)chmod(f[i+1][j][k|(1<<l)],f[i][j][k]);
					else chmod(f[i+1][j+1][k|(1<<l)],f[i][j][k]);
				}
			}
		}
	}
	for(int j=0;j<=n-m;j++)ans=(ans+f[n][j][(1<<n)-1])%p;
	printf("%d",ans);
	return 0;
}
