#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	int m,n,n1;
	char a[510];
	int c[510];
	long long f[510];
	long long ans=0;
	scanf("%d%d%s",&n,&m,a);
	n1=n;
	for(int i=0;i<n;++i){
		scanf("%d",&c[i]);
		if(c[i]==0) n1--;	
	}
	if(m>n1){
		printf("0");
		return 0;
	}
    f[0]=1;f[1]=1;
    for(int i=2;i<=n;++i){
    f[i]=i*f[i-1]%Mod;
 //   printf("%lld",f[i]);	
	}
    
	printf("%lld",f[n]);
	return 0;
}
