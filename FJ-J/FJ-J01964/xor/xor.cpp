#include<bits/stdc++.h>
using namespace std;
int n,k,sum,max,maxn;
int a[100015],s[10015];
 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]),s[i]=s[i-1]*a[i];
}
	for(int i=1;i<=n;i++){
		sum=s[i]^k;
		
		cout<<sum; 
	}
	return 0;
}
