#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],z,k,t,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	k=n*m;
    for(int i=1;i<=k;i++){
    	scanf("%d",&a[i]);
	}
	z=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==z){
		   t=i;
		}
	}
	x=t/n,y=t%n;
	if(y){
	   x++;
	}
	else{
		y=n;
	}
	if(x%2==0){
	   y=n-y+1;
	}
	printf("%d %d\n",x,y);
	return 0;
}
