#include <bits/stdc++.h>
using namespace std;
int n,m,a[120];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    int x=1,y=1,k=1;
    for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]){
			x+=k;
		}
		if(x>n&&y%2==1){
			y++;
			k=-1;
			x+=k;
			continue;
		}
		if(x<1&&y%2==0){
			y++;
		    k=1;
			x+=k;
			continue;
		}
	}
	printf("%d %d\n",y,x);
    return 0;
}
