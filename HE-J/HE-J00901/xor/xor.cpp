#include<bits/stdc++.h>
using namespace std;

int n,a[500010],k,sum=0;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]&a[i+1]==k)
			sum+=1;
		else
			if(a[i]==k)
				sum+=1;
	printf("%d",sum);
} 

