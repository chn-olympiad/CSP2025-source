#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int f[505],n,m,a[505],num;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%c",&a[i]);
		if(a[i]) num++;
	}
	if(num<m || num==0){
		printf("0");
		return 0;
	}
	if(m==1){
		long long ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%M;
		printf("%lld",ans);
		return 0;
	}
	if(num==n){
		long long ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%M;
		printf("%lld",ans);
		return 0;
	}
	if(m==n){
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}
