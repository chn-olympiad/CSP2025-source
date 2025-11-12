#include<bits/stdc++.h>
using namespace std;
int n,m;
int ci=1;
int cc;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1){
			cc=a[i];
		}
	}
	int z=n*m;
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[ci]==cc){
					printf("%d %d",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				ci++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[ci]==cc){
					printf("%d %d",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				ci++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}