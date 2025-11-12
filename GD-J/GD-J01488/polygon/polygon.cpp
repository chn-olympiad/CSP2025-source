#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long answer=0;
long long a[5050],zhui[5050]; 

bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(1+a,1+a+n,cmp);
	for(long long i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			zhui[i]=zhui[i-1]+1;
		}
		else{
			zhui[i]=zhui[i-1];
		}
		answer+=zhui[i];
	}
	if(answer%10==0){
		answer-=answer/10;
	}
	printf("%lld",answer);
	return 0;
}
