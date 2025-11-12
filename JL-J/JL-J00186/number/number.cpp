#include<bits/stdc++.h>
using namespace std;
char s[10000005];
long long a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	long long sum=0;
	long long b=sizeof(s);
	for(long long i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(long long i=sum;i>=1;i--){
		printf("%lld",a[i]);
	}
	return 0;
}
