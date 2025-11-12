#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",a+i);
	int k=a[1],pos;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)if(a[i]==k){
		pos=i;
		break;
	}
	int x=(pos-1)/n+1,y=(pos-1)%n+1;
	if(x%2==0)y=n+1-y;
	printf("%d %d\n",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
