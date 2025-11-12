#include<bits/stdc++.h>
using namespace std;
int n,m,t,x=1,y=1,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1],sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i]==t){t=n*m-i;break;}
	while(t){
		if(y&1) x++;
		else x--;
		if(x>n) x=n,y++;
		if(!x) x=1,y++;
		t--;
	}
	printf("%d %d",y,x);
	return 0;
}
