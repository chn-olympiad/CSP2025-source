#include<iostream>
#include<algorithm>
using namespace std;
const int si=20;
int n,m,a[si*si],small_R,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	small_R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==small_R){
			small_R=n*m-i+1;
			break;
		}
	hang=int((small_R-1)/n);
	printf("%d ",hang+1);
	small_R-=hang*n;
	if(hang%2==0)printf("%d",small_R);
	else printf("%d",n-small_R+1);
	return 0;
}
