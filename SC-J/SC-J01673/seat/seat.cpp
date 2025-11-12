#include<bits/stdc++.h>
using namespace std;
int n,m;
int c=1,r=1;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)	scanf("%d",&a[i]);
	int sr = a[1];
	sort(a,a+n*m);
	int cnt = 0;
	while(a[n*m-cnt] != sr) cnt++;
	c = cnt%n==0?cnt/n:cnt/n+1;
	r = cnt%n==0?n:cnt%n;
	r = c%2==0?n-r+1:r;
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//暂无问题。 