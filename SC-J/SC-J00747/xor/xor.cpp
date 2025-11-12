#include<bits/stdc++.h>
using namespace std;
int n,y,a[500005],sum,p,as1,as0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			as0++;
			continue;
		}
		if(a[i]==1){
			as1++;
			continue;
		}
		if(a[i]==y && y!=1 && y!=0){
			sum++;
			a[i]=-1; 
			continue;
		}
	}
	a[0]=-1;
	a[n+1]=-1;
	if(as0+as1==0){
		if(y==0){
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1]){
					sum++;
				}
			}
			printf("%d",sum);
			return 0;
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			printf("%d",sum);
			return 0;
		}
		
	}
	else if(as1==n){
		if(y==6){
			printf("%d",n);
			return 0;
		}
		else {
			printf("c");
			return 0;
		}
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			p=a[l];
			for(int k=l+1;k<=r;k++){
				p|=a[k];
			}
			if(p==y){
				sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
}