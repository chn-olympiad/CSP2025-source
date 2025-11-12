#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[105],sc,x=1,y=1,t;
bool cmp(const int &p1,const int &p2){
	return p1>p2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)
		scanf ("%d",&a[i]);sc=a[0];
	sort(a,a+n*m,cmp);
	for (int i=0;i<n*m;i++){
		if(a[i]==sc){
			printf("%d %d",x,y);break;
		}
		if((i+1)%n==0)			x++;
		else if((i+1)%(2*n)>n)	y--;
		else 					y++;
	}
	return 0;
}
