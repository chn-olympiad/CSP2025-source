#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++)
		if(a[i]==r){
			int x=i/n,y=i%n;
			if(x*n<i) x++;
			if(y==0) y=n;
			if(x%2==0) y=(n-y+1);
			printf("%d %d",x,y);
			break;
		}
	return 0;
}
