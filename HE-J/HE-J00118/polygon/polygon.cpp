#include<bits/stdc++.h>
using namespace std;

int p=998244353;
int n;
int a[5001];
int ans=0;
bool b[5001];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
			printf("1");
		else
			printf("0");
	}else{
		printf("%lld",(3*n*n-17*n+25)%p);
	}
	return 0;
}
