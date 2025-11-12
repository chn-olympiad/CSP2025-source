#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1101];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			printf("%d %d",x,y);
			break;
		}
		y+=c;
		if(y==n+1)x++,y=n,c*=-1;
		if(y==0)x++,y=1,c*=-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 100
