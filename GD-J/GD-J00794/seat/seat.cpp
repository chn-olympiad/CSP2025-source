#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],x,y,t,k,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	t=n*m;
	scanf("%d",&o);
	a[0]=o;
	for(int i=1;i<t;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+t);
	for(int i=1;i<=t;i++){
		if(a[t-i]==o)	k=i;	
	}
	x=(k+n-1)/n;
	if(x%2==0)	y=n-k%n+1;
	else{
		y=k%n;
		if(y==0)	y=n;
	}
	printf("%d %d",x,y); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

