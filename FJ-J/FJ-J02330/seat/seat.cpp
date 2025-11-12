#include<iostream>
#include<algorithm>
using namespace std;
int a[1000],b[20][20],n,m,ans=0,c,d;
bool cmp(int x,int y){
	return x>y;
}
int dfs(int dx,int dy,int s){
	if(a[s]==ans)
	{
		c=dx;
		d=dy;
		return 0;
	}
	if(dx+1<=n&&dy%2==1)
	dfs(dx+1,dy,s+1);
	else if(dx-1>=1&&dy%2==0)
	dfs(dx-1,dy,s+1);
	else if((dx+1>n&&dy%2==1)||(dx==1&&dy%2==0))
	dfs(dx,dy+1,s+1);
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i=0;
	cin>>n>>m;
	for(;i<n*m;i++)
	cin>>a[i];
	ans=a[0];
	sort(a,a+n*m,cmp);
	dfs(1,1,0);
	cout<<d<<" "<<c;
	return 0;
}
//100 97
//99 98
