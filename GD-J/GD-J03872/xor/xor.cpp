#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[5*100000+5],A=1,B=1,ans,d[1005][1005],b[1005][1005],g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i][1]=a[i];
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(A==1){
		printf("%d",n/2);
	}
	else if(B==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i+1]==1) ans++;
				}
			}
			printf("%d",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			printf("%d",ans);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(d[i][1]==k){
				b[i][1]=1;
			}
		}
		for(int j=2;j<=n;j++){
			for(int i=1;i+j-1<=n;i++){
				d[i][j]=d[i][j-1]^d[i+j-1][1];
				if(d[i][j]==k){
					b[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i=g+i){
			g=1;
			for(int j=1;j+i-1<=n;j++){
				if(b[i][j]==1) {
					ans++;
					g=j;
					break;
				}
			}
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
