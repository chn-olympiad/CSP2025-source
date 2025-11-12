#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[15][15],cj[105],cnt,x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&cj[i]);
	}
	x=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=cj[++cnt];
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j]=cj[++cnt];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==x){
				printf("%d %d",i,j);
			}
		}
	} 
	return 0;
} 
