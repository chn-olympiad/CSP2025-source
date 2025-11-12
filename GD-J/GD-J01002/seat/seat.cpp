#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],d,p,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	d=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			p=n*m-i+1;
			break;
		}
	}
	ansx=(p-1)/n+1,ansy=(p-1)%n+1;
	if(ansx%2==0) ansy=m-ansy+1;
	printf("%d %d",ansx,ansy);
	return 0;
}
