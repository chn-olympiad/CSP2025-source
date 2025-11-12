#include<bits/stdc++.h>
using namespace std;
int t[2],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int s=0;
	for(int i=0;i<n;++i){
		scanf("%d",&s);
		if(s)++t[1];
		else ++t[0];
	}
	printf("%d",n/2);
	return 0;
}

