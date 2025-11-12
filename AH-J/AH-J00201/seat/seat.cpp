#include <bits/stdc++.h>
using namespace std;
bool cmp(int X,int Y){
	return X>Y;
}
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int u=n*m;
	for(int i=1;i<=u;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	int k=1;
	int o=1;
	while(1){
		if(a[k]==r){
			printf("%d %d\n",y,x);
			break;
		}
		x+=o;
		if(x>n||x<=0){
			x-=o;
			o=-o;
			y+=1;
		}
		k++;
	}
	return 0;
}
