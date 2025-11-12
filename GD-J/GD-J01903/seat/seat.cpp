#include <bits/stdc++.h>
using namespace std;
int n,m,a[120],s[20][20],x,l=0;
bool cmp(int p,int q){
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	l=0;
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if((i%2)==1){
			for(int j=1;j<=n;j++){
			    if(a[++l]==x){
			    	printf("%d %d",i,j);
			    	break;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++l]==x){
					printf("%d %d",i,j);
					break;
				}
			}
		}
	}
	return 0;
 } 
