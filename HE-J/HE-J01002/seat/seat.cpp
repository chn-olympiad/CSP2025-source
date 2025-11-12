#include<bits/stdc++.h>
using namespace std;

int n,m,a[101];

bool calc(const int &x,const int &y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1];
	sort(a+1,a+n*m+1,calc);
	int top=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>0;j--){
				top++;
				if(a[top]==x){
					printf("%d %d",i,j);
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				top++;
				if(a[top]==x){
					printf("%d %d",i,j);
				}
			}	
		}
	}
}
