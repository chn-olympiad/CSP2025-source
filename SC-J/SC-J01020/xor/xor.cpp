#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long a[1000001], n=0, k=0, b[1000001][30], ck[30], lb[1000001], lc=0, m=0;
    scanf("%lld%lld", &n, &k);
   	for(int j=1;k!=0;j++){
    		ck=k%2;
    		k/2;
		}    
    for(int i=1;i<=n;i++){
    	scanf("%lld", &a[i]);
    	for(int j=1;a[i]!=0;j++){
    		b[i][j]=a[i]%2;
    		a[i]/=2;
    		lb[i]++;
		}
		for(int j=1;j<=lb[i]/2;j++){
			int k=b[j];
			b[j]=b[lb[i]-j+1];
			b[lb[i]-j+1];
		}
	}
	lc=lb[1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lb[i]>lc){
				lc=lb[i];
			}
			for(int k=1;k<=lc){
				if(b[j]==b[i]){
					m++;
				}
			}
		} 
	}
	printf("%d", m);
	return 0;
} 