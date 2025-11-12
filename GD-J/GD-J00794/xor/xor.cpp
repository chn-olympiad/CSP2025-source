#include<bits/stdc++.h>
using namespace std;
long long dp[500000],k;
int a[500000],n,m,f=0;
bool b[500000],o,d[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(k==a[i]){
			b[i]=1;
			m++;
		}
		dp[i]=a[i];
	}
	for(int l=1;l<n;l++){
		while(b[f])	f++;
		for(int i=f;i+l<n;i++){
			if(!b[i]){
				dp[i]=a[i]^dp[i+1];
				if(dp[i]==k){
					for(int k=1;k<=l;k++)	b[i-k]=1;
					for(int k=i;i<=l+k;i++)	b[i]=1;
					m++;
				}
			}
			
		}
	}
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

