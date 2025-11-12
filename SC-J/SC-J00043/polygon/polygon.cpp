/**
 * @file polygon.cpp 
 * @version:  1.2.0
 * @author: dpl
 * @date: 2025-11-01 10:41:26
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans=0,add=1;
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(add<=n){

		for (int i=1;i<=(n-add+1)%MOD;i++){
			int max_len=0;
			int total_len=0;
			for (int j=i;j<=(i+add-1)%MOD;j++){
				max_len=max(max_len%MOD,a[j]%MOD);
				total_len+=a[i]%MOD;
			}
			if (total_len%MOD>=max_len*2%MOD) ans++;
		}
		add++;
	}
	printf("%d",ans%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}