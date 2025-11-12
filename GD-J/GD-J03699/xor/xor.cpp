#include<bits/stdc++.h>
using namespace std;
long long a[500010],sumn[500010],n,k,ans = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sumn[i] = sumn[i-1]^a[i];
	}
	int Last_End = 0;
	for(int r=1;r<=n;r++){
		for(int l=1;l<=r;l++){
			if((sumn[r]^sumn[l-1])==k&&l>Last_End){
				ans++;
				Last_End = r;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
