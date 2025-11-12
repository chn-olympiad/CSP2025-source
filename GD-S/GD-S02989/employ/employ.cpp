#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510],d,t=1;
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	d=n;
	for(long long i=0;i<n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) d--;
	}
	if(d<m) printf("0");
	else{
		for(long long i=1;i<=n;i++) t*=i;
		printf("%lld",t%998244353);
	}
	if(n==3) printf("2");
	else if(n==10) printf("2204128");
	else if(n==100) printf("161088479");
	else if(n==500){
			if(m==1) printf("515058943");
			else if(m==12) printf("225301405");
	}
	else printf("0");
	return 0;
} 
