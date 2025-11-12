#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],k,x,y,j;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1,j=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			break;
		}
		if((y==n&&j==1)||(y==1&&j==-1))x++;
		else y+=j;
		if(i%n==0)j=-j;
	}
	printf("%d %d",x,y);
	return 0;
}
