#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[1010][1010],sum;
bool f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
            b[i][j]=a[i];
			if(i!=j){   
			   for(int k=i+1;k<=j;k++){
			       b[i][j]=b[i][j]^a[k];	
			   }
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i][j]==k){
			   bool s=0;
			   for(int k=i;k<=j;k++){
			   	   if(f[k]==1){
			   	   	  s=1;
				   }
			   }
			   if(s==0){
			   	  sum++;
			   	  for(int k=i;k<=j;k++){
			   	   	  f[k]=1;
				  }
			   }
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
