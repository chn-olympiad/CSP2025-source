#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
bool cmp(int a,int c){
	return a>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int rn=n+1,rm=m+1;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int q=a[1],x,y;
	sort(a+1,a+n*m+1,cmp);
	int b[n+1][m+1];
	bool flag=0;
	for(int i=1,j=1;i<=m;i++){
		if(i%2!=0){
			for(int k=1;k<=n;k++){
				b[k][i]=a[j];
				if(a[j]==q){
					printf("%d %d",i,k);
					flag=1;
					break;
				}
				j++;
			}
		}else{
			for(int k=n;k>=1;k--){
				b[k][i]=a[j];
				if(a[j]==q){
					printf("%d %d",i,k);
					flag=1;
					break;
				}
				j++;
			}
		}
		if(flag){
			break;
		} 
	}
	return 0;
}
