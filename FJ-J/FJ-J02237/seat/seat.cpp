#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,c,r,o;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(x==a[1]){
		printf("1 1");
		return 0;
	}
	c=1,r=1;
	for(int i=2;i<=n*m;i++){
		if(i%n==1){
			c++;
			o++;
		}
		else if(o%2==0) r++;
		else r--;
		if(a[i]==x){
			printf("%d %d",c,r);
			return 0;
		}
	}
	return 0;
}
