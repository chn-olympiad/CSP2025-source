#include<bits/stdc++.h> 
using namespace std;
int n,k,sum,a[500005],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j>=i,j<=n;j++){
			for(int k=i;k<=j;k++){
				s=(s^a[k]);
				if(s==k){
					sum++;
					break;
				}
			}
		}
	}
	printf("%d",sum);	
	return 0;
}
