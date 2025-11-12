#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0,ax=1,j=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			ans++;
			ax=i;
			j=0;
			continue;
		}
		else{
			j=j^a[i];
			if(j==k){
				j=0;
				ans++;			
				ax=i;
				continue;
			}
			for(int l=ax;l<i-1;l++){
				int j1=j^a[l];
				if(j1==k){
					j=0;
					ax=i;
					ans++;		
					break;
				}
			}	
		}
	}
	printf("%d",ans);
	return 0;	
} 
