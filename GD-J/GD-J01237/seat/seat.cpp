#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
struct Node
{
	int grade,id;
	bool operator<(const Node &x)const
	{
		return grade>x.grade;
	}
};
Node stu[MAXN];
int n,m,rk,x,ansr,ansc,y;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)
	{
		stu[i].grade=read();
		stu[i].id=i;
		if(i==1) x=stu[1].grade;
	}
	sort(stu+1,stu+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(stu[i].grade==x)
		{
			rk=i;
			break;
		}
	}
	ansc=ceil(rk*1.0/n);
	y=rk%n;
	if(y==0) y+=n;
	if(ansc&1==1) ansr=y;
	else ansr=n-y+1;
	printf("%d %d",ansc,ansr);
	return 0;
}
