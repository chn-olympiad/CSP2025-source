#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010][2],cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][1]);
		if(a[i][1]==k) cnt++,a[i][2]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]!=1){
			for(int l=i;l<n;l++){
				if(a[l][2]==1) continue;
				for(int r=l+1;r<=n;r++){
					if(a[r][2]==1) break;
					int ans=a[l][1];
					for(int j=l+1;j<=r;j++) ans^=a[j][1];
					if(ans==k) cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
