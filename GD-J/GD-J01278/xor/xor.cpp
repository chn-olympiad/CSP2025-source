#include <bits/stdc++.h>
using namespace std;
int n,f[1005][1005];
long long h,s[500005],jj=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&h);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		if(s[i]==h){
			f[i][i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^s[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
				jj=s[j]^s[k];
				if(jj==h){
					f[i][j]=max(f[i][j],f[i][k]+1);
				}
				jj=s[k]^s[i-1];
				if(jj==h){
					f[i][j]=max(f[i][j],1+f[k+1][j]);
				}
			}
		}
	}
	printf("%d",f[1][n]);
	
	
	
	
	return 0;
}
