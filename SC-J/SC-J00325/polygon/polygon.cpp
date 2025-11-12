#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=3;i<=n;i++){
		for(int x=1;x<=n-2;x++){
			for(int y=x+1;y<=n-1;y++){
				for(int z=y+1;z<=n;z++){
					if(a[x]+a[y]+a[z]>2*max(a[z],max(a[x],a[y])))cnt++;
				}
			}
		}
	}
	printf("%d",cnt%998244353);
	return 0;
} 