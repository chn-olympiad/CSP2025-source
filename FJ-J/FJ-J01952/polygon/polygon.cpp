#include<bits/stdc++.h> 
using namespace std;
long n,andd,maxx,ans;
long broud[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&broud[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
		maxx=max(max(broud[i],broud[j]),broud[k]);
		andd=broud[i]+broud[j]+broud[k];
		if(andd>maxx*2) ans++;
	}
	}
	}
	printf("%d",ans);
	return 0;
}
