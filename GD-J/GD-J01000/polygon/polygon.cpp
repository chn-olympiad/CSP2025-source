#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a,b,c;
	scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
	int ansdfg=0;
	if(a+b+c>2*max(a,max(b,c))) ansdfg++;
	printf("%d",ansdfg);
	return 0;
} 
