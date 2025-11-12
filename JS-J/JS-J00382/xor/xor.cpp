#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int re=1;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0) ans++;
		}
	}
	else{
		re=0;
		for(int i=0;i<n;i++){
			if(a[i]!=1){
				re=1;
				}
		}
	}
	if(re==0){
		if(k==1){
			ans=n;
		}
		else{
			ans=0;
		}
	}
	printf("%d",ans);
	return 0;
}
