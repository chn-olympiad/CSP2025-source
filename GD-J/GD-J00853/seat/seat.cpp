#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int tmp,lct;
void f(int rank)
{
	int dir=1;//1down
	int x=1,y=1;
	for(int i=2;i<=rank;i++)
	{
		if(x+dir>n or x+dir<1)y++,dir=-dir;
		else x+=dir;
	}
	cout<<y<<" "<<x;
}
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	lct=find(a+1,a+1+n*m,tmp)-a;
//	cout<<lct<<endl;
	f(lct);
	return  0;
}
