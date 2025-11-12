#include<bits/stdc++.h>

#define INPUT long long
using namespace std;
INPUT Read()
{
	INPUT Re=0,f=1;
	char n;
	while((n=getchar())<'0'||n>'9')
	{
		if(n==EOF)exit(0);
		if(n=='-')f=-1;
	}
	Re=f*(n-48);
	while((n=getchar())>='0'&&n<='9')
		Re=(Re<<1)+(Re<<3)+(n-48)*f;
	return Re;
}

const int N=100000;
int n;
long long Ans;
struct Node
{
	int a,b,c,z;
}Inp[N+10];
vector<Node>Vec[4];

bool CmpABC(Node x,Node y)
{
	if(x.z==1)return min(x.a-x.b,x.a-x.c)>min(y.a-y.b,y.a-y.c);
	if(x.z==2)return min(x.b-x.a,x.b-x.c)>min(y.b-y.a,y.b-y.c);
	if(x.z==3)return min(x.c-x.a,x.c-x.b)>min(y.c-y.a,y.c-y.b);
	return false;
}

bool CmpBC(Node x,Node y)
{
	if(Vec[2][0].z==1&&Vec[3][0].z==2)return x.a-x.b>y.a-y.b;
	if(Vec[2][0].z==1&&Vec[3][0].z==3)return x.a-x.c>y.a-y.c;
	if(Vec[2][0].z==2&&Vec[3][0].z==1)return x.b-x.a>y.b-y.a;
	if(Vec[2][0].z==2&&Vec[3][0].z==3)return x.b-x.c>y.b-y.c;
	if(Vec[2][0].z==3&&Vec[3][0].z==1)return x.c-x.a>y.c-y.a;
	if(Vec[2][0].z==3&&Vec[3][0].z==2)return x.c-x.b>y.c-y.b;
	return false;
}

void Work()
{
	for(int i=1;i<=3;i++)Vec[i].clear();
	Vec[1].push_back((Node){0,0,0,1});
	Vec[2].push_back((Node){0,0,0,2});
	Vec[3].push_back((Node){0,0,0,3});
	n=Read();Ans=0;
	for(int i=1;i<=n;i++)
	{
		Inp[i].a=Read(),
		Inp[i].b=Read(),
		Inp[i].c=Read();
		if(Inp[i].a>=Inp[i].b&&Inp[i].a>=Inp[i].c)Inp[i].z=1,Vec[1].push_back(Inp[i]),Ans=Ans+Inp[i].a;
		else if(Inp[i].b>=Inp[i].a&&Inp[i].b>=Inp[i].c)Inp[i].z=2,Vec[2].push_back(Inp[i]),Ans=Ans+Inp[i].b;
		else Inp[i].z=3,Vec[3].push_back(Inp[i]),Ans=Ans+Inp[i].c;
	}
	if(Vec[1].size()<Vec[2].size())swap(Vec[1],Vec[2]);
	if(Vec[2].size()<Vec[3].size())swap(Vec[2],Vec[3]);
	if(Vec[1].size()<Vec[2].size())swap(Vec[1],Vec[2]);
	// for(int i=1;i<=3;i++)
	// {
	// 	printf("D%d:",i);
	// 	for(int j=1;j<(int)Vec[i].size();j++)
	// 		printf("(%d,%d,%d,%d) ",Vec[i][j].a,Vec[i][j].b,Vec[i][j].c,Vec[i][j].z);
	// 	putchar('\n');
	// }
	if((int)Vec[1].size()-1<=n/2)printf("%lld\n",Ans);
	else
	{
		sort(Vec[1].begin()+1,Vec[1].end(),CmpABC);
		while((int)Vec[1].size()-1>n/2)
		{
			Node Now=Vec[1][(int)(Vec[1].size())-1];
			Vec[1].erase(Vec[1].end()-1);
			bool Flag=0;
			if(Now.z==1&&Vec[2][0].z==2)Flag=Now.a-Now.b<Now.a-Now.c;
			if(Now.z==1&&Vec[2][0].z==3)Flag=Now.a-Now.c<Now.a-Now.b;
			if(Now.z==2&&Vec[2][0].z==1)Flag=Now.b-Now.a<Now.b-Now.c;
			if(Now.z==2&&Vec[2][0].z==3)Flag=Now.b-Now.a>Now.b-Now.c;
			if(Now.z==3&&Vec[2][0].z==1)Flag=Now.c-Now.a<Now.c-Now.b;
			if(Now.z==3&&Vec[2][0].z==2)Flag=Now.c-Now.a>Now.c-Now.b;

			if(Flag)
			{
				if(Now.z==1&&Vec[2][0].z==2)Ans-=Now.a,Ans+=Now.b;
				if(Now.z==1&&Vec[2][0].z==3)Ans-=Now.a,Ans+=Now.c;
				if(Now.z==2&&Vec[2][0].z==1)Ans-=Now.b,Ans+=Now.a;
				if(Now.z==2&&Vec[2][0].z==3)Ans-=Now.b,Ans+=Now.c;
				if(Now.z==3&&Vec[2][0].z==1)Ans-=Now.c,Ans+=Now.a;
				if(Now.z==3&&Vec[2][0].z==2)Ans-=Now.c,Ans+=Now.b;
				Now.z=Vec[2][0].z;
				Vec[2].push_back(Now);
			}
			else
			{
				if(Now.z==1&&Vec[3][0].z==2)Ans-=Now.a,Ans+=Now.b;
				if(Now.z==1&&Vec[3][0].z==3)Ans-=Now.a,Ans+=Now.c;
				if(Now.z==2&&Vec[3][0].z==1)Ans-=Now.b,Ans+=Now.a;
				if(Now.z==2&&Vec[3][0].z==3)Ans-=Now.b,Ans+=Now.c;
				if(Now.z==3&&Vec[3][0].z==1)Ans-=Now.c,Ans+=Now.a;
				if(Now.z==3&&Vec[3][0].z==2)Ans-=Now.c,Ans+=Now.b;
				Now.z=Vec[3][0].z;
				Vec[3].push_back(Now);
			}
		}

		if(Vec[2].size()<Vec[3].size())swap(Vec[2],Vec[3]);

		if((int)Vec[2].size()-1<=n/2)printf("%lld\n",Ans);
		else
		{
			sort(Vec[2].begin(),Vec[2].end(),CmpBC);
			while((int)Vec[2].size()-1>n/2)
			{
				Node Now=Vec[2][(int)(Vec[2].size())-1];
				Vec[2].erase(Vec[2].end()-1);
				if(Now.z==1&&Vec[3][0].z==2)Ans-=Now.a,Ans+=Now.b;
				if(Now.z==1&&Vec[3][0].z==3)Ans-=Now.a,Ans+=Now.c;
				if(Now.z==2&&Vec[3][0].z==1)Ans-=Now.b,Ans+=Now.a;
				if(Now.z==2&&Vec[3][0].z==3)Ans-=Now.b,Ans+=Now.c;
				if(Now.z==3&&Vec[3][0].z==1)Ans-=Now.c,Ans+=Now.a;
				if(Now.z==3&&Vec[3][0].z==2)Ans-=Now.c,Ans+=Now.b;
			}
			printf("%lld\n",Ans);
		}
	}
	return;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=Read();
	for(;t;t--)Work();
	return 0;
 } 
