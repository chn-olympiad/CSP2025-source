#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N*N];
bool cmp(int a,int b){
	return a>b;
}
int cj;
int zwh;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]) zwh++;
	}
	zwh++;
	int t=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				t++;
				if(t==zwh){
					printf("%d %d",i,j);
					return 0;
				}
			} 
		}else{
			for(int j=m;j>=1;j--){
				t++;
				if(t==zwh){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
