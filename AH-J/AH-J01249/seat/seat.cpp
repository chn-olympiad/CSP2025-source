#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r,num=1;
bool f(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+1+n*m,f);
	int j=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			while(j<=n){
				if(a[num]==r){
					printf("%d %d",i,j);
					return 0;
				}
				num++,j++;
			}
			j=n;
		}else{
			while(j>=1){
				if(a[num]==r){
					printf("%d %d",i,j);
					return 0;
				}
				num++,j--;
			}
			j=1;
		}
	}
	return 0;
}
