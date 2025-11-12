#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=110;
struct node{
	int s,id;
}a[N];
const int dx[]={1,-1};
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);//正式提交 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i].s<<' ';//调试，记得注释掉 
	//cout<<endl;//调试，记得注释掉 
	int x=1,y=1,id=0,nxt=0;
	while(id<=n*m)
	{
		id++;
		//cout<<x<<' '<<y<<endl;//调试，记得注释掉 
		if(a[id].id==1)
		{
			cout<<y<<' '<<x;
			break;
		}
		int nx=x+dx[nxt];
		if(nx<1||nx>n)
		{
			y++;
			nxt=(nxt+1)%2;
		}
		else x+=dx[nxt];
		
	}
	return 0;
}//期望100pts 