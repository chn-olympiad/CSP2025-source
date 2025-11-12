#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cop(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>a[1];int p=a[1],x=1,y=1,v=1;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cop);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p){cout<<y<<" "<<x;return 0;
		}
		x+=v;
		if(x<=0||x>n) x-=v,y++,v=-v; 
	}
	return 0;
}
/*
froepen("number.in","r",stdin);
froepen("number.out","w",stdout);
freopem("number.in","r",stdin);
freopem("number.out","w",stdout);
上面这些东西都不是用来诈骗你的，只是用来坑你的-luogu good163
不会这道题有人排序时没排n*m个吧 awa 
*/
