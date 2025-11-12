#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
bool f=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]&&i!=1)f=false;
	}
	if(f){
		if(k==a[1])printf("%d",n);
		else if(k==0)printf("%d",n/2);
	}
	return 0;
}
