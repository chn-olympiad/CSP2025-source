#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
//输入行和列n,m注意：和最后输出的区分 
//3 3
//94R 95 96 97 98 99 100 93 92 
//先排序下面的成绩sort
//0 0 0
//0 0 0
//0 0 0
//100 99 98 97 96 95 94R 93 92
//蛇形填数打表到找到小R的位置break
//100 0 0 
//99  0 0 i++ 
//98  0 0 i++ 
//100 95 0 i++ 
//99  96 0 i++ 
//98  97 0 i++ 
//100 95 94R i++找到了break 输出i除以m列 的是小R的列数 余数是行数 注意：先列在行 
//99  96 0
//98  97 0
int n=0,m=0;
int a[105];
int a1=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++)
	{
		cin>>a[i];
		if(i==1)
			a1=a[i];
	}
	int l=n*m;
	for(int i=1;i<=n*m;i++,l--)
	{
		for(int j=1;j<=l-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		} 
	}
//	for(int i=1;i<=(n*m);i++)
//	{
//		cout<<a[i];
//	}
	int s=1,r=0;
//	cout<<a1<<endl;
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i]<<endl;
		if(a[i]==a1)
		{
//			cout<<s<<" "<<r<<endl;
			r=s;
		}
		s++;
	} 
	s=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s==r)
			{
//				cout<<s<<endl<<r<<endl;
				cout<<i<<" "<<j;
			}
			s++;
		}
	} 
	return 0;
} 
