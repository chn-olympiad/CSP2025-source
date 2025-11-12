#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005]={};
	long long   b[1000005]={};
	long long a[1000005]={};
	long long  x=0;
	scanf("%lld",&x);
	for(long long  i=0;i<100005;i++){
		scanf("%lld",&a[i]);
	}
	long long  j=0;
	for(int i=0;i<1000005;i++){
		if(a[i] >='0' && a[i] <= '0'){
			b[j]=a[i]-'0';
			j++;
		}
	}	
	for(int k=0;k<j;k++){
		for(long long  l=k;l<j;l++){
			int c=b[l];
			b[l]=b[l+1];
			b[l+1]=c;
		}
	}
	for(long long  k=0;k<j;k++){
		printf("%lld",b[k]);

	}

	return 0;
}
