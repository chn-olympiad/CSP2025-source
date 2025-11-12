#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b,c[20][20],x=1,y=0;
bool o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	b=a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		for(int j=i;j>1;j--){
			if(a[j]<=a[j-1])
				break;
			int x=a[j];
			a[j]=a[j-1];
			a[j-1]=x;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(o)
			c[x][--y]=a[i];
		else
			c[x][++y]=a[i];
		if(a[i]==b){
			printf("%d %d",x,y);
			return 0; 
		}
		if(o&&y==1)
			x++,o=0,y=0;
		if(!o&&y==n)
			x++,o=1,y=n+1;
	}
	return 0;
}
