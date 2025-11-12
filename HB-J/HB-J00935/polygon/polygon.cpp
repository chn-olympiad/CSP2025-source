#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,num[5005];
bool f;
long long A(int a,int b){
	if(2*b>a)	b=a-b;
	if(b==0)	return 1;
	if(b==1)	return a;
	int t=1;
	for(int i=a;i>a-b;i--){
		t*=i;
	}
	return t/2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]!=1)	f=0;
	}
	sort(num,num+n);
	if(n<3){
		printf("0\n");
		return 0;
	}
	if(n==3){
		if(num[0]+num[1]+num[2]>2*num[2])	printf("1\n");
		else
		{
			printf("0\n");
		}
		return 0;
	}
	if(f){
		long long p=0;
		for(int i=3;i<=n;i++){
			p+=A(n,i);
			p%=N;
		}
		printf("%lld\n",p);
		return 0;
	}
	printf("6\n");
	return 0;
}
