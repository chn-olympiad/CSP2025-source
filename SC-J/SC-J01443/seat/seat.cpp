#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],mm[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=n*m,R,num=0;
	for(int i=1;i<=l;i++){
		scanf("%d",&a[i]);
		if(i==1) R=a[i];
	}
	sort(a+1,a+l);
	for(int i=l;i>=1;i--){
		if(R==a[i]) break;
		num++;
	}
	int idx=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				idx++;
				if(num==idx){
					printf("%d %d",i,j);
					return 0;
				}
				
			}
		}
		else{
			for(int j=n;j>=1;j--){
				idx++;
				if(num==idx){
					printf("%d %d",i,j);
					return 0;
				}
				
			}
		}
	}
	return 0;
}