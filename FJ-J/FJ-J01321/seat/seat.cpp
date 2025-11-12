#include<bits/stdc++.h>
using namespace std;
int m,n,s[1000],pm,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int k=m*n;
	for(int i=1;i<=k;i++)
		scanf("%d",&s[i]);
	int mun=s[1];
	
	sort(s+1,s+k+1);
	for(int l=1;l;l++){
		if(s[l]==mun){
			pm=k-l+1;
			break;
		}
	}
	if(pm%n) c=pm/n+1;
	else c=pm/n;
	pm%=n;
	if(c%2) r=pm;
	else r=n-pm+1;
	if(!r) r=n;
	printf("%d %d",c,r);
	return 0;
}
