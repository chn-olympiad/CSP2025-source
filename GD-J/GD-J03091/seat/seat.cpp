#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],k=1,x,f;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				if(a[k]==x){
					printf("%d %d",j,i);
					f=1;
				}
				k++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[k]==x){
					printf("%d %d",j,i);
					f=1;
				}
				k++;
			}
		}
		if(f){
			break;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
