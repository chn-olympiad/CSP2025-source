#include <bits/stdc++.h>
using namespace std;
int n,m,b,c,ans=0;
bool a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for (int i=100; i>=0; i--) a[i]=0;
	scanf("%d%d",&n,&m);
	scanf("%d",&c);
	a[c]=1;
	for (int i=1; i<n*m; i++){
		scanf("%d",&b);
		a[b]=1;
	}
	for (int i=100; i>=0; i--){
		if(a[i]==1) ans++;
		if(i==c && a[i]==1) break;
	}
	int ls,hs;
	ls=(ans/(2*n))*2;
	hs=ans%(2*n);
	if (hs==0){
		hs++;
		printf("%d %d",ls,hs);
		return 0;
	}
	if(hs>n){
		ls+=2;
		hs=2*n-hs+1;
		printf("%d %d",ls,hs); 
		return 0;
	}
	if(hs<=n){
		ls++;
	}
	printf("%d %d",ls,hs); 
	return 0;
} 
