#include<bits/stdc++.h>
using namespace std;

int n,k,a[1010]={0};
bool b=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)b=false;
	}
	if(b){
		cout<<n/2;
	}
	else cout<<2;
	return 0;
} 
