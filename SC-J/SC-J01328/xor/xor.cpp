#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define xo(i,j) xo[j]^xo[i-1]
int xo[N],P[N],
top=1,n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&P[i]);
		if(i==1) xo[i]=P[i];
		else xo[i]=xo[i-1]^P[i];
	}
	for(int i=1,j,R=0;i<=n;i++){
		j=i;bool B=1;
		if(P[i]==k){R=i;continue;}
		while(B){if(xo(i,j)==k){
		B=0;break;}else j++;
			if(j>n) break;
		}if((!B)&&R<i) R=j,ans++;
	}printf("%d",ans);
	return 0;
}