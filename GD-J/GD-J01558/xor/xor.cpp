#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp=0;
			for(int k=i;k<=j;k++){
				tmp=tmp^a[k];
			}
			if(tmp==k){
				i=j,sum++;
				break;
			}
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
