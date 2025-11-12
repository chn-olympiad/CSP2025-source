#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmb(int tx,int ty){
	return tx>ty;
//sort-use
}
int a[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i=i+1)
		for(int j=1;j<=m;j=j+1)scanf("%d",&a[(i-1)*m+j]);
	//input
	int tx=a[1];
	//printf("a[1]=%d.\n",tx);
	int tn=1;
	sort(a+1,a+n*m+1,cmb);
	for(int i=1;i<=m;i=i+1){
		if(i%2==0){
			for(int j=n;j>=1;j=j-1){
				if(tx==a[tn]){
					printf("%d %d\n",i,j);
					return 0;
				//found-ans
				}
				tn=tn+1;
			//check-each-row
			}	
		//check-each-line-up
		}
		else{
			for(int j=1;j<=n;j=j+1){
				if(tx==a[tn]){
					printf("%d %d\n",i,j);
					return 0;
				//found-ans
				}
				tn=tn+1;
			//check-each-road
			}	
		//check-each-line-down
		}
	//each-seat
	}
	return 0;
//end-T2
//check-09:33-maybe-100
//check-11:50-100
}
