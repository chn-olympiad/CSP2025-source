#include<bits/stdc++.h>
using namespace std;
bool a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a1 = 0,n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		a[x] = 1;
		if(i == 1){
			a1 = x;
		}
	}
	int tot = 0;
	for(int i = 100;i>=1;i--){
		if(a[i] == 1 && i == a1){
			tot++;
			break;
		}else if(a[i] == 1){
			tot++;
		}
	}
//	printf("tot = %d\n",tot);
	int num = ceil(tot*1.0/n);
	printf("%d ",num);
//	printf("%d ",tot);
	
	if(num % 2 == 1)
		printf("%d ",(tot-1)%(n)+1);
	else
		printf("%d",n-((tot-1)%n));
	return 0;
}
