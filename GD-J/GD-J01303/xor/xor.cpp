#include<bits/stdc++.h>
using namespace std;
int c[500002],n,m,m1,kl,oo;
bool mm[27],cc[500002][27],jj[27];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if(c[i]==m){
		oo++;}
	}
	printf("%d",oo); 
	
	return 0;
}
