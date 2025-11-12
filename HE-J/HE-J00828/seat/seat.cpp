#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d\n",&n,&m);
	int k=n*m,r;
	scanf("%d ",&r);
	for(int i=2;i<=k;i++){
		cin>>a[i];
	}
	a[1]=r;
	sort(a+1,a+1+k);
	int x=0,y=1;
	for(int i=k;i>=1;i--){
		if(y%2!=0){
			x++;
			if(x>n){
				x--;
				y++;
			}
		}else{
			x--;
			if(x==0){
				x++;
				y++;
			}
		}
		if(a[i]==r){
			printf("%d %d",y,x);
			return 0;
		}
	}
	
}
