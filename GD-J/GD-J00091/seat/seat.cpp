#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,cnt=1,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==num) num=i;
	while(num>n) num-=n,cnt++;
    if(cnt%2==0){
    	x=n-num+1;
    	y=cnt;
	}else{
		x=num;
		y=cnt;
	}
	printf("%d %d",y,x);
	return 0;
}
