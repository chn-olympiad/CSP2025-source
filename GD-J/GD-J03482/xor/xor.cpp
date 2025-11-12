#include<bits/stdc++.h>
using namespace std;
int a[500005],k,n,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k)l++;
	}
	if(n<=2){
		if(n==2&&a[n]^a[n-1]==k)l++;
	}
	else{
		int u;
		for(int i=1;i<n;i++){
			u=a[i];
			if(u==0);
			else
			for(int j=i+1;j<=n;j++){
				if(a[j]==0);
				else{
					u=u^a[j];
					if(u==k){
						l++;
					}
				}
			}
		}
	}
	printf("%d",l);
	return 0;
}
