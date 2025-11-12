#include<bits/stdc++.h>
using namespace std;
int n,m,a[300],an,lastx=0,lasty=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	an=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
			lastx+=1;
		}else{
			if(lastx%2==1){
				lasty+=1;
			}else{
				lasty-=1;
			}
				
		}
		if(a[n*m-i+1]==an){
			printf("%d %d",lastx,lasty);
			break;
		}
	}
	
	return 0;
}