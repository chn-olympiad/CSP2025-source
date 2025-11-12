#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x,y;
	int k=a[1];
	sort(a+1,a+(n*m)+1);
	int sum=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[sum]==k){
					x=i;
					y=j;
				}
				sum--;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[sum]==k){
					x=i;
					y=j;
				}
				sum--;
			}	
		}
	}
	printf("%d %d",x,y);
	return 0;
} 
