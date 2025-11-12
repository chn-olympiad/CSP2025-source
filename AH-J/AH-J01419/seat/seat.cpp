#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++){
			scanf("%d",&a[(i-1)*m+j]);
		}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*m+j]==x) {
					printf("%d %d",i,j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*m+(n-j+1)]==x) {
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
    return 0;
}
