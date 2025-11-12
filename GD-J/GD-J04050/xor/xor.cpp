#include<bits/stdc++.h>
using namespace std;
int n,k,sm;
int a[500005];
bool usd[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(usd[i]==1){
			continue;
		}
		else if(a[i]==k){
			sm++;
			usd[i]=1;
			continue;
		}
		int xsm=a[i];
		for(int j=i+1;j<=n;j++){
			if(usd[j]==1){
				break;
			}
			xsm^=a[j];
			if(xsm==k){
				sm++;
				for(int k=i;k<=j;k++){
					usd[k]=1;
				}
				break;
			}
		}
	}
	printf("%d",sm);
	return 0;
}
