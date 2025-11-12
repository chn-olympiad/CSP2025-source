#include<iostream>
#include<algorithm>
#include<vector> 
#include<cstring>
using namespace std;//预计30~50 
const int MAXN = 100005;
struct node{
	long long a,b,c,id,go;
}stu[MAXN];
int isgo[MAXN];
int fir(node x)
{
	if(x.a > x.b && x.a > x.c)
		return 1;
	else if(x.b > x.a && x.b > x.c)
		return 2;
	else
		return 3;
}
int sec(node x)
{
	if(fir(x) == 1)
		if(x.b > x.c)
			return 2;
		else
			return 3;
	else if(fir(x) == 2)
		if(x.a > x.c)
			return 1;
		else
			return 3;
	else
		if(x.a > x.b)
			return 1;
		else
			return 2;
}
int thi(node x)
{
	if(fir(x) != 1 && sec(x) != 1)
		return 1;
	else if(fir(x) != 2 && sec(x) != 2)
		return 2;
	else
		return 3;
}
bool cmp1(node x,node y)
{
	return x.a>y.a;
}
bool cmp2(node x,node y)
{
	return x.b>y.b;
}
bool cmp3(node x,node y)
{
	return x.c>y.c;
}
void solve()
{
	int n;
	scanf("%d",&n);
	memset(isgo,0,sizeof(isgo));
	vector<node> choose[5][5];//choose[x][y]表示所有以x为第y选择的成员 
	for(int i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
		stu[i].id = i;
		//cout<<fir(stu[i])<<' '<<sec(stu[i])<<' '<<thi(stu[i])<<endl;
		choose[fir(stu[i])][1].push_back(stu[i]);
		choose[sec(stu[i])][2].push_back(stu[i]);
		choose[thi(stu[i])][3].push_back(stu[i]);
		
	}
	for(int i = 1;i <= 3;i++)
	{
		sort(choose[1][i].begin(),choose[1][i].end(),cmp1);
		//cout<<"a:"<<endl;for(node i : choose[1][i]) cout<<i.a<<' '<<i.id<<endl;
		sort(choose[2][i].begin(),choose[2][i].end(),cmp2);
		//cout<<"b:"<<endl;for(node i : choose[2][i])cout<<i.b<<' '<<i.id<<endl;
		sort(choose[3][i].begin(),choose[3][i].end(),cmp3);
		//cout<<"c:"<<endl;for(node i : choose[3][i])cout<<i.c<<' '<<i.id<<endl;
	}
	int pa = 0,pb = 0,pc = 0;
	long long ans = 0;
	for(int k = 1;k <= 3;k++)
	{
		for(int i = 0;i < choose[1][k].size();i++)
		{
			node nowx = choose[1][k][i];
			if(pa+1<=n/2)
			{	
				if(isgo[nowx.id] == 0)
				{
					pa++;
					//cout<<nowx.id<<endl;
					ans+=nowx.a;
					isgo[nowx.id] = 1;
				}
			}
			else
				break;
		}
		for(int i = 0;i < choose[2][k].size();i++)
		{
			node nowx = choose[2][k][i];
			if(pb+1<=n/2)
			{
				if(isgo[nowx.id] == 0)
				{
					pb++;
					//cout<<nowx.id<<endl;
					ans+=nowx.b;
					isgo[nowx.id] = 2;
				}
			}
			else
				break;
		}
		for(int i = 0;i < choose[3][k].size();i++)
		{
			node nowx = choose[3][k][i];
			if(pc+1<=n/2)
			{
				if(isgo[nowx.id] == 0)
				{
					pc++;
					//cout<<nowx.id<<endl;
					ans+=nowx.c;
					isgo[nowx.id] = 3;
				}
			}
			else
				break;
		}
	}
	//for(int i =1;i <= n;i++)
		//cout<<isgo[i]<<' ';
	printf("%d\n",ans);
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;	
} 
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
