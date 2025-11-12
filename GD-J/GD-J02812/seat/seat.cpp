#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],t,c,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			for(int j=n;j<=m*n;j+=n){
				if(i>=j-n+1&&i<=j){
					c=j/n;
					if((j/n)%2==0){
						r=j-i+1;
						break;
					}
					else{
						r=n-(j-i);
						break;
					}
				}
			}
		break;
		}
		
	}
	printf("%d %d",c,r);
	return 0;
}
