#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[(i-1)*m+j]);
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[(i-1)*m+j]==x){
				printf("%d ",i);
				if(i%2) printf("%d",j);
				else printf("%d",m-j+1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
