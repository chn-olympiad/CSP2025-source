#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[110];
int n,m,k,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	x=b[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-1;j++){
			if(b[j+1]>b[j]){
			    k=b[j+1];
			    b[j+1]=b[j];
			    b[j]=k;
		    }
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==0){
				if(b[j*n-(i-1)]==x){
					printf("%d %d",j,i);
					break;
				}
			}else{
				if(b[(j-1)*n+i]==x){
					printf("%d %d",j,i);
					break;
				}
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 