#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],cnt,ma,l,r,shu=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1]^a[i]);
	}
	for(l=1;l<=n;l++){
		if(shu!=-1) l=shu;
		shu=-1;
		for(r=l;r<=n;r++){
			if(l>ma&&l<=r){
				if((s[r]^s[l-1])==k){
					cnt++;
					ma=max(ma,r);
				}
			}else if(l<=ma){
				shu=ma+1;
				break;
			}
		}
	}
	/*for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			if(l>ma){
				if((s[r]^s[l-1])==k){
					cnt++;
					ma=r;
				}
			}
		}
	}*/
	printf("%d",cnt);
	return 0;
}
