#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
struct node{
	int score;
	int index;
}b[1005];
//自定义比较函数，为后面对成绩排序做铺垫 
bool com1(const node &a,const node &b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	//预处理蛇形座位表
	memset(a,0,sizeof(a));
	int cnt=1;
	int x=1,y=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
			while(x<=n) a[x++][y]=cnt++;	
		else
			while(x>=1) a[x--][y]=cnt++;	
		y++;
		cnt--;
	}
	//处理小明在哪个座位
	int r_score; 
	for(int i=1;i<=n*m;++i) 
	{
		cin>>b[i].score;
		b[i].index=i;
	}
	r_score=b[1].score;
	int l=n*m;
	sort(b+1,b+l+1,com1);
	for(int i=1;i<=l;++i)
	b[i].index=i;
	int r_index=0;
	for(int i=1;i<=l;i++)
	{
		if(b[i].score==r_score)
		r_index=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{	
			if(a[i][j]==r_index) 
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	
	}	
}//CCF is great(too diffcult!!!)

