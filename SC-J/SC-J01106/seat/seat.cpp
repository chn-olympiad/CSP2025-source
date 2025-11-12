#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c^48),c = getchar();
	return x * f;
}
const int N = 105;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n * m;i++)	a[i] = read();
	int x = a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int c = 0;
	for(c = 1;c <= n * m;c++)
		if(a[c] == x)	break;
	printf("%d ",(c+n-1) / n);
	int y = ((c + 2 * n - 1) / (2 * n)) * (2 * n)- c;
	if(y < n)	printf("%d\n",y+1);
	else	printf("%d\n",c % (2 * n)); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}