#include <bits/stdc++.h>
using namespace std;
int n;
int bi=0;
int a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	bi=max(a,max(b,c));
	if(a+b+c>bi*2){
		printf("1");
	}
	else{
		printf("0");
	}
	
	
	return 0;
}
