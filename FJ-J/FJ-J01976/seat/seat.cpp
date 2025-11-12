#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[10*10+1],b[16][16];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++,cnt++){
				if(a[cnt]==R){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--,cnt++){
				if(a[cnt]==R){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}
