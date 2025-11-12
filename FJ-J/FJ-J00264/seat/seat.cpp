#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)  scanf("%d",a+i);
	int id=1;
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])  ++id;
	int col=(id+n-1)/n,row;
	id-=(col-1)*n;
	if(col&1)  row=id;
	else  row=n-id+1;
	printf("%d %d",col,row);
	return 0;
}
