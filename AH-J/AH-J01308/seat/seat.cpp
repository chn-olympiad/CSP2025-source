#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m,s[105],x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==1) a[i][j]=i;
			else{
				if(i==1){
					if(j%2==0) a[i][j]=j*n;
				    else a[i][j]=(j-1)*n+1;
				}else{
					if(j%2==0) a[i][j]=a[i-1][j]-1;
					else a[i][j]=a[i-1][j]+1;					
				}
				}
		}
	}
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
		if(i==1) x=s[i];
		}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==x){
			y=i;break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==y){
				printf("%d %d\n",j,i);break;
				}
			}
		}
	return 0;
}
