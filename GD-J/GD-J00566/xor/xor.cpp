#include<bits/stdc++.h>
using namespace std;
int n,ans,bj;
long long k,a[500010];
int x=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	bj=a[1]; 
	if(k){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1 && a[i+1]==1){
				a[i+1]=0;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
