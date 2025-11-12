#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,k=1;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
		scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=m; i++)
		if(i&1){
			for(int j=1; j<=n; j++)
				if(a[k++]==x){
					printf("%d %d\n",i,j);
					return 0;
				}
		}else{
			for(int j=n; j; j--)
				if(a[k++]==x){
					printf("%d %d\n",i,j);
					return 0;
				}
		}
	return 0;
}
