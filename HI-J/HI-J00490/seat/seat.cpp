#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,i=1,j=1;
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int p=1;p<=n*m;p++){
		scanf("%d",&a[p]);
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp); 
	for(int z=1;z<=n*m;z++){
		if(a[z]==x){
			printf("%d ",j);
			printf("%d",i);
			return 0;
		}
		if(j%2!=0){
			if(i<n){
				i++;
			}else if(i==n){
				j++;
			}
		}else if(j%2==0){
			if(i>1){
				i--;
			}else if(i==1){
				j++;
			}
		}
	}
	return 0;
}
