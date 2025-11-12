#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
int sa,a[N],n,m,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	int pos=1;
	for(int i=1;i<=l;i++){
		cin>>a[i];
		if(a[i]>a[1]) pos++;
	}
	if(pos%n) x=pos/n+1;
	else x=pos/n;
	if(x%2==0) y=n-pos%n+1;
	else y=pos-(x-1)*n;
	printf("%d %d\n",x,y);
	return 0;
}
/*
2 2
99 100 97 98
*/
