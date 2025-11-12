#include<bits/stdc++.h>
using namespace std;
int n,a[5005],hz[5005],zz[5005][5005],m,h,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		hz[i]=a[i]+hz[i-1];
		zz[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			zz[i][j]=max(zz[i][j-1],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			h=hz[j]-hz[i-1];
			m=zz[i][j]*2;
			if(h>m) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
