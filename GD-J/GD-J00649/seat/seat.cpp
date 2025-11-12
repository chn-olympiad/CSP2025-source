#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		scanf("%d",&a[i]);
		if(a[i]>=a[1])cnt++;
	}
	int x=cnt/n,y=cnt%n;
	if(y!=0){
		if(x%2==0){
			printf("%d %d",x+1,y);
			return 0;
		}else{
			printf("%d %d",x+1,n-y+1);
			return 0;
		}
	}else{
		if(x%2==0){
			printf("%d %d",x,1);
			return 0;
		}else{
			printf("%d %d",x,n);
			return 0;
		}
	}
	return 0;
}
