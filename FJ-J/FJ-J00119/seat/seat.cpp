#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cmp(int c,int cc){
	return c>=cc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	int t=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(a[t]==sum){
					printf("%d %d",i,j);
					return 0;
				}t++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[t]==sum){
					cout<<i<<" "<<j;
					return 0;
				}t++;
			}
		}
	}return 0;
}
