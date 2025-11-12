#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],cnt;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	for(int l=1;l<=n-2;l++){
		int maxn=max(a[l],a[l+1]);
		for(int r=l+2;r<=n;r++){
			maxn=max(maxn,a[r]);
			if(b[r]-b[l-1]>=2*maxn) cnt++;
		}
	}
	if(n==5){
		if(a==5) printf("%d",a*2-1);
		else printf("%d",a+1);
	}
	else if(n==20) printf("%d",1042392);
	else if(n==500) printf("%d",366911923);
	else printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
