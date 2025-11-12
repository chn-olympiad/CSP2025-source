#include<bits/stdc++.h>
using namespace std;
int n,m,sc,a,se=1;
int main(){
	freopen("seat.in","r",stdin);	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>a;
	for(int i=1;i<n*m;i++){
		scanf("%d",&sc);
		if(sc>a) se++;
	}
	int em,en=1;
	em = 1+(se-1)/n;
	en += (em%2==0?n-(se-1)%n-1:(se-1)%n);
	printf("%d %d",em,en);
	return 0;
}
