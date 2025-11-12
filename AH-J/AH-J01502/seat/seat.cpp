#include "iostream"
#include "cstdio"
using namespace std;
int n,m,a[1005],sum=0;
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf ("%d",&a[i]);
	}
	for (int i=2;i<=n*m;i++){
		if (a[i]>a[1]) sum++;
	}
	int x=1,y=1;
	for (int i=1;i<=sum;i++){
		if (y%2==1){
			if (x<n) x++;
			else y++;
		}
		else{
			if (x>1) x--;
			else y++;
		}
	}
	printf ("%d %d\n",y,x);
	return 0;
}
