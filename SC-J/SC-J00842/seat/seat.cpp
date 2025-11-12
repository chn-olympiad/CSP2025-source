#include<bits/stdc++.h>
using namespace std;

const int MAXN=14;
int n,m;
int a[MAXN];
int aufsatz=1;
int x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i=2;i<=n*m;i++){scanf("%d",&a[i]);if(a[i]>a[1]) aufsatz++;}
	if(aufsatz<=n) x=1;
	else x=aufsatz/n+1;
	if(!(aufsatz%n)){if(x&1) y=n;else y=1;}
	else{
		if(x&1) y=aufsatz%n;
		else y=n-(aufsatz%n)+1;
	}
	printf("%d %d\n",x,y);
	return 0;
}