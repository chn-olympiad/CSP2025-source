#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+nm+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k]==r){
					printf("%d %d",i,j);
					return 0;
				}
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[k]==r){
					printf("%d %d",i,j);
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
} 
