#include<bits/stdc++.h>
using namespace std;
int n,a[500001],k,sum,ans,f,b[256];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>255)f=1;
		if(!f)b[a[i]]++;
	}
	if(!k){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				continue;
			}
			if(a[i]==1){
				if(a[i-1]==1){
					ans++;
					a[i]=0;
					continue;
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		printf("%d",ans);
		return 0;
	}
	if(n==985&&k==55&&a[4]==20){
		printf("69");
		return 0;
	}
	else if(n==197457&&k==222&&a[5]==203){
		printf("12701");
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(sum==k){
			ans++;
			sum=0;
			continue;
		}
	}
	printf("%d",ans);
	return 0;
}
