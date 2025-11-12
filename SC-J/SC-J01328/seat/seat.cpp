#include<bits/stdc++.h>
using namespace std;
int n,m,Gr[105],
r,c,Pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&Gr[i]);
		if(Gr[i]>Gr[1]) Pm++;
	}
	for(int i=1,a=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				if(a==Pm){
					printf("%d %d",i,j);
					return 0;
				}
				else a++;	
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a==Pm){
					printf("%d %d",i,j);
					return 0;
				}
				else a++;
			}
		}
	}
	return 0;
}
