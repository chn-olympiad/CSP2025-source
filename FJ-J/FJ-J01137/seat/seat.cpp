#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
int n,m,a[105],k,w[15][15],ai;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ai++;
				if(a[ai]==k){
					printf("%d %d",i,j);
					return 0; 
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ai++;
				if(a[ai]==k){
					printf("%d %d",i,j);
					return 0; 
				}
			}
		}
	}
	return 0;
}
