#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N]={1},n,cnt0,cnt1,cnt11,now,k,ans,b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
	}
	if(cnt0+cnt1==n){
		if(k==1){
			printf("%d",cnt1);
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==a[i-1]&&a[i]==1){
					now++;
				}else{
					cnt11+=now/2;
					now=0;
				}
			}
			printf("%d",cnt11+cnt0);
		}else{
			printf("0");
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}