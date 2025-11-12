#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,ans=0;
int a[510000],b[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=cnt;j--){
			if((b[i]^b[j])==k){
				ans++;
				cnt=i;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
