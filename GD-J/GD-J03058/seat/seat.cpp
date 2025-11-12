#include <bits/stdc++.h>
using namespace std;
const int N=11;
int a[N][N],c[N*N];
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	int ns=1;
	for(int i=1;i<=n*m;i++) scanf("%d",&c[i]);
	int cnt=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(c[ns]==cnt){
					printf("%d %d",j,i);
					return 0;
				}
				ns++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(c[ns]==cnt){
					printf("%d %d",j,i);
					return 0;
				}
				ns++;
			}
		}
	}
	
	return 0;
}
