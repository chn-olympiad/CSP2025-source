#include<bits/stdc++.h>
using namespace std;
int vis[13][13];
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	bool f=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	int xr=a[0];
	sort(a,a+n*m,cmp);
	int c=0,lr;
	for(int j=0;j<m;j++){
		if(j%2==0){
			for(int i=0;i<n;i++){
				vis[i][j]=a[c];
				if(a[c]==xr){
					printf("%d %d",j+1,i+1);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				c++;
			}
		}else{
			for(int i=n-1;i>=0;i--){
				vis[i][j]=a[c];
				if(a[c]==xr){
					printf("%d %d",j+1,i+1);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				c++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
