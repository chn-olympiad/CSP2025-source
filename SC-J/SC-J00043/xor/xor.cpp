/**
 * @file xor.cpp 
 * @version:  2.0.0
 * @author: dpl
 * @date: 2025-11-01 10:40:58
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],dp[500050],total=0,ans=0;
bool find(int sum){
	for (int i=1;i<=n;i++){
		if (a[i]==sum) return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	total=a[1];
	for (int i=2;i<=n;i++){
		total^=a[i];
		if (find(total)){
			ans=2;
		}
		
	}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}