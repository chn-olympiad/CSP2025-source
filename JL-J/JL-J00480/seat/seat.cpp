#include <bits/stdc++.h>
using namespace std;
#define N 100
int a[N];
int seat[11][11];
bool cmp(int x,int y);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int seat_zs=n*m;
	for(int i=0;i<seat_zs;i++)
		scanf("%d",a+i);
	int k=a[0];
	sort(a,a+seat_zs,cmp);
	int t=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				seat[i][j]=a[t];
				t++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				seat[i][j]=a[t];
				t++;
			}
		}
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==k){
				printf("%d %d\n",i,j);
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}

	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
