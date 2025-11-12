#include<cstdio>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int n,k,ans,a[500005],f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((a[i]^a[j-1])==k)f[i]++;
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}

/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
