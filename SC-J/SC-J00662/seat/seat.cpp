#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",a+i);
	}
	num = a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,dir = 1;
	for(int cnt=1;cnt<=n*m;cnt++){
		if(a[cnt] == num){
			printf("%d %d",j,i);
			return 0;
		}
		else if(i == n &&dir == 1){
			j++;dir=-1;
		}
		else if(i == 1 &&dir == -1){
			j++;dir = 1;
		}else{
			i += dir;
		}
	}
} 
