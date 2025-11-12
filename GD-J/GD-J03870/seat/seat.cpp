#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,h=1,x=1,y=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(a[h]!=s){
		if(y%2==1) x++;
		else x--;
		if(x==n+1) x=n,y++;
		if(x==0) x=1,y++;
		h++;
	}
	printf("%d %d",y,x); 
	return 0;
}
