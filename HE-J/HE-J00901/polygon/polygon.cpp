#include<bits/stdc++.h>
using namespace std;

int n,a[10001],sum=0;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-2;i++)
		for(int j=i;j<=n;j++){
			int x=max(max(a[j],a[j+1]),a[j+2]);
			if(a[j]+a[j+1]+a[j+2]>x*2)
				sum++;
		}
	printf("%d",sum);
} 

