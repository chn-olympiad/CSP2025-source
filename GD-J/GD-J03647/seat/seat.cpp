#include<iostream>
#include<algorithm>
using namespace std;
const int N=107;
int n,m,a[N],b,id,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	b=a[1]; 
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++) if(b==a[i]) id=i;
	y=(id-1)/n+1;
	if(y%2) x=(id-1)%n+1;
	else x=n-(id-1)%n;
	printf("%d %d",y,x);
	return 0; 
}
/*
2 2
98 99 100 97
*/
