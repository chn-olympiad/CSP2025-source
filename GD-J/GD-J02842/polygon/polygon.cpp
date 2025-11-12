#include<bits/stdc++.h>
using namespace std;
int n;
int a[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==3) {
		for(int i=1;i<=3;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		if(a[3]<a[1]+a[2]) printf("1");
		else printf("0"); 
	}
	return 0;
} 
