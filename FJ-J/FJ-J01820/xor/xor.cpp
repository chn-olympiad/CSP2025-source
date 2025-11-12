#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN],f[MAXN][MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=f[i][j-1]^a[i];
			if(f[i][j]==k)ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
