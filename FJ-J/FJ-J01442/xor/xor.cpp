#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N*5];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool fr=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fr=1;
	}
	if(k==0&&fr==0){
		printf("%d",n/2);
	}
	return 0;
} 
