#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[101],r,t,x=1,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r){t=n*m+1-i;break;}
	while(t>n){
		t-=n;
		x++;
	}
	if(x%2==1)y=t;
	else if(x%2==0)y=m+1-t;
	printf("%d %d",x,y);
	return 0;
}
