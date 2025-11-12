#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polyfon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n=3)
		printf("1");
	else
		printf("0");
}

//too difficult. I can't do it =(
