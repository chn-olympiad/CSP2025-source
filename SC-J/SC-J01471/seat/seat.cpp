#include <bits/stdc++.h>
using namespace std;

const int N=110;
int n,m,x=1,y=1,ok,ansx,ansy;
int id,a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	id=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==id){
			ansx=x,ansy=y;
			break;
		}
		if(!ok){
			if(x==n)
				y++,ok=1;
			else
				x++;
		} else{
			if(x==1)
				y++,ok=0;
			else
				x--;
		}
	}
	printf("%d %d",ansy,ansx);
	return 0;
}