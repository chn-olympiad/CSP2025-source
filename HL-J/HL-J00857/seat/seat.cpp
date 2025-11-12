#include <bits/stdc++.h>
using namespace std;
int a;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m-1;
	int r,sn=1,sm=1;
	scanf("%d",&r);
	for(int i=1;i<=t;i++){
		scanf("%d",&a);
		if(a>r){
			if(sn==n){
				sn=1;
				sm++;
			}
			else{
				sn++;
			}
		}
	}
	if(sm%2==0){
		printf("%d %d",n-sn+1,sm);
	}
	else{
		
		printf("%d %d",sn,sm);
	}
	fclose(stdin);
	fclose(stdout);
}