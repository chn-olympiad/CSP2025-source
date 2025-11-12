#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin)
freopen("xor.out","w",stdout)
int a[100010],b[100010];
int n,k,l=1,r=1,ans=0;
scanf("%d%d",&n,&k);
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	b[i]=b[i-1]*a[i];
}
for(l=0;l<n;l++){
	for(r=l;r<=n;r++){
		if(b[r]^b[l-1]==k){
			printf("%d %d\n",l,r);
			l=r+1;
			r=1;
			ans++;
		}
	}
	printf("%d",2^0); 
	
}




return 0;
}

