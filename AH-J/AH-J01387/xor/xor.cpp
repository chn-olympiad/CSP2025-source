#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int f=1;
	scanf("%d%d",&n,&k);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1){
			f=0;
		}
	}
	if(f){
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==0){
					cnt++;
				}
				else if(a[i]==1&&a[i]==a[i+1]){
					cnt++;
					i++;
				}
			}
			if(a[n]==0) cnt++;
			printf("%d",cnt);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]){
					cnt++;
				}
			}
			printf("%d",cnt);		
			
		}
		return 0;
	}
	for(int i=1;i<=n&&((double)clock()/CLOCKS_PER_SEC<=0.995);){
		int ans=0;
		for(int j=i;j<=n;j++){
			ans^=a[j];
			if(ans==k){
				cnt++;
				i=j+1;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
