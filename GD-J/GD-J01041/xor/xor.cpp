#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[1005][1005],s[N],tmp,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			f[i][i]=1;
		}
	}
	if(n>1000&&k<=1){
		a[0]=3;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i]==1&&a[i-1]==1){
						ans++;
						a[i]=3;
					}
				}
			}
		}
			printf("%d",ans);
			return 0;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
//		printf("%d ",s[i]);
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			tmp=s[r]^s[l-1];
			if(tmp==k) f[l][r]=1;
			for(int cut=l;cut<r;cut++){
				f[l][r]=max(f[l][r],f[l][cut]+f[cut+1][r]);
//				printf("%d %d %d %d\n",len,l,r,f[l][r]);
			}
		}
	}
	printf("%d",f[1][n]);
}
