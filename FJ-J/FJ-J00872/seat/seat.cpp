#include <bits/stdc++.h>
using namespace std;
int a[120],n,m,v,x,y,id;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a[1]);
    for(int i=2;i<=n*m;i++){
	    scanf("%d",&a[i]);
	}v=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			id=i;
			break;
		}
	}
	if(id<=n)x=1;
	else if(id%n==0)x=id/n;
	else x=id/n+1;
	if(x%2==0){
		y=n-(id-(x-1)*n)+1;
	}else y=id-(x-1)*n;
	printf("%d %d",x,y);
    return 0;
}  
