#include<bits/stdc++.h>
using namespace std;
int n,m,a[1101101],c,mm=1,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	c=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i;i--){
		j++;
		if(a[i]==c){
			printf("%d ",mm);
			if(j%(2*n)<=n && j%(2*n)>=1){
				printf("%d",j%(2*n));
			}
			else if(j%(2*n)==0){
				printf("1");
			}
			else{
				printf("%d",2*n-j%(2*n)+1);
			}
			break;
		}
		if(j%n==0){
			mm++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
