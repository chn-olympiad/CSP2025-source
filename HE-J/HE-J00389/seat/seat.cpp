#include <bits/stdc++.h>
using namespace std;
int n,m,a[205];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf ("%d%d",&n,&m);
	int x = n*m;
	for (int i=1;i<=x;i++)
	    scanf ("%d",&a[i]);
	int c = a[1];
	sort (a+1,a+x+1,cmp);
	int w;
	for (int i=1;i<=x;i++)
	    if(a[i]==c)
	       w = i;
	int X;
	if (w%n==0)
	    X = w/n;
	else
	    X = w/n+1;
	int Y;
	if (w%n==0){
		if (X%2==0)
		    Y = 1;
		else
		    Y = n;
	}else{
		if (X%2==0)
		    Y = n-w%n+1;
		else
		    Y = w%n;
	}
	printf ("%d %d",X,Y);
}
