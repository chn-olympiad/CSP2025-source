#include<bits/stdc++.h>
using namespace std;
int n,m,dx=1,dy=1,flag=0,mark,a[1010],lp=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) mark=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mark){
			mark=i;
			break;
		}
	}
	mark=n*m-mark+1;
	for(int i=1;i<=n*m;i++){
		if(i==mark){
			printf("%d %d",dy,dx);
			break;
		}
		if( (dx==n || (dx==1 && i!=1)) && lp==1){
			dy++;
			flag++; flag%=2;
			lp=0;
		}
		else{
			if(flag==0) dx++;
			else dx--;
			lp=1;
		}
	}
	return 0;
}
