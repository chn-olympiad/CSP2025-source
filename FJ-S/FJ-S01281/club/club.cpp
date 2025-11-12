#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>

using namespace std;
int n,t,stand;long long sum=0;
const int MAXN=100005;
struct student{
	int a[4];
	int d[4];
	int maxn;
}stu[MAXN];
int c[4];
bool compare(int i,int j)
{
	return i<j;
}
int cmp(int x,int y,int z)
{
	if(x>=y&&x>=z){
		sum+=x;return 1;
	}
	if(y>=x&&y>=z){
		sum+=y;return 2;
	}
	if(z>=y&&z>=x){
		sum+=z;return 3;
	}
}
int solve()
{
	int best,club;
	if(c[1]>=c[2]&&c[1]>=c[3]){
		best=c[1];club=1;
		}
	if(c[2]>=c[1]&&c[2]>=c[3]){
		best=c[2];club=2;
		}
		if(c[3]>=c[1]&&c[3]>=c[2]){
		best=c[3];club=3;
		}
	if(best>stand)
	{
	//vector<int> vec;
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(stu[i].maxn ==club)
		{
			if(club==1)q.push(min(stu[i].d[1],stu[i].d[3]));
			if(club==2)q.push(min(stu[i].d[1],stu[i].d[2]));
			if(club==3)q.push(min(stu[i].d[2],stu[i].d[3]));
		}
		
	}
	stack<int> st;
	while(!q.empty())
	{
		st.push(q.top());
		q.pop();
	}
	while(best>stand)
		{
			
			sum-=st.top();
			st.pop();
			best--;
		}
		return sum;
}
else return sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
scanf("%d",&t);
while(t--)
{
	sum=0;memset(c,0,sizeof(c));
scanf("%d",&n);stand=n/2;
for(int i=1;i<=n;i++)
{
	//cin>>stu[i].a[1]>>stu[i].a[2]>>stu[i].a[3];
	scanf("%d%d%d",&stu[i].a[1],&stu[i].a[2],&stu[i].a[3]);
	stu[i].d[1]=abs(stu[i].a[2]-stu[i].a[1]);stu[i].d[2]=abs(stu[i].a[3]-stu[i].a[2]);stu[i].d[3]=abs(stu[i].a[1]-stu[i].a[3]);
	
	switch(cmp(stu[i].a[1],stu[i].a[2],stu[i].a[3]))
	{
		case 1:{
			c[1]++;stu[i].maxn=1;
			break;
		}
		case 2:{
			c[2]++;stu[i].maxn=2;
			break;
		}
		case 3:{
			c[3]++;stu[i].maxn=3;
			break;
		}
	}
}
printf("%d\n",solve());
//cout<<solve()<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}

