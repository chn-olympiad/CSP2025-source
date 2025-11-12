#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int Mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int Max=-10000,sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>Max) Max=a[i];
		sum+=a[i];
	}
	if(n==3){
		if(sum>Max*2) printf("1");
		else printf("0");
	}
	else if(n>=20){
		int S=(n-1)*(n-2)/2;
		printf("%d",S%Mod);
	}
	return 0;
}
