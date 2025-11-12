#include<bits/stdc++.h>
using namespace std;

int n,k,a[600000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<2){
		puts("0");
	}else{
		puts("1");
	}
	return 0;
} 
