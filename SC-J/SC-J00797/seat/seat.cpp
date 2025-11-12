#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n,m,p=0,a[maxn];
bool cmp(int u1,int u2){
	return u1>u2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	p=a[1]; sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,cnt=1;
	while(p!=a[cnt]){
		if(y%2) x++;
		else x--;
		if(x==n+1) y++,x=n;
		if(x==0) y++,x=1;
		cnt++;
	}
	printf("%d %d\n",y,x);
	return 0;
}