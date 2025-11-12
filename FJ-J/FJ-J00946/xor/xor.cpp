#include<bits/stdc++.h>
using namespace std;

int a[500005],n,k,s[500005],ans=0,x=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int l,r;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(r=1;r<=n;r++){
		for(l=x;l<=r;l++){
			int sum=a[l];
			for(int i=l+1;i<=r;i++){
				sum^=a[i];
			} 
			if(sum==k){
				ans++;
				x=r+1;
				l=x;
			}
		} 
	}
	printf("%d",ans);
	return 0;
} 
