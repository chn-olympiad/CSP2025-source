#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,x;
bool cmp(const int x,const int y){
	if(x<y){
		return false;
	}
	return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1){
			num=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				x++;
				if(num==a[x]){
					printf("%d %d",i,j);
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				x++;
				if(num==a[x]){
					printf("%d %d",i,j);
					break;
				}
			}
		}
	}
	return 0;
}
