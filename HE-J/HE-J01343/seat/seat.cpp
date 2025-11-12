#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,x=1,y=1;
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	l=a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(l==a[i]){
			break;
		}
		if(x%2==0)
		{
			if(y==1){
				x++;
			}
			else{
				y--;
			}
		}
		else{
			if(y==n){
				x++;
			}
			else{
				y++;
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
