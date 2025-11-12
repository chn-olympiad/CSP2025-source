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
const int N=10000;
const int M=11000000; 
int n,m,k;
long long Inp[20][N+10],Ans;

const int GraphN=N;
const int GraphM=M*2;
class Graph
{
public:
    int m,Head[GraphN+10],Next[GraphM+10],To[GraphM+10];
    long long Val[GraphM+10];
    Graph(){m=0;memset(Head,-1,sizeof Head);}
    void Add(int u,int v,long long w)
    {
        To[++m]=v;
        Val[m]=w;
        Next[m]=Head[u];
        Head[u]=m;
    }
}G;
struct Edge
{
    int Num;
    long long Val;
    friend bool operator<(Edge x,Edge y)
    {
        return x.Val>y.Val;
    }
};
bool Vis[N+10];
priority_queue<Edge>Que;

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=Read(),m=Read(),k=Read();
    for(int i=1;i<=m;i++)
    {
        int u=Read(),v=Read();
        long long w=Read();
        G.Add(u,v,w);
        G.Add(v,u,w);
    }
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++)
            Inp[i][j]=Read();

    for(int Zz=1;Zz<=k;Zz++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                G.Add(i,j,Inp[Zz][0]+Inp[Zz][i]+Inp[Zz][j]);
            }
    
    
    // Prim
    Que.push({1,0});
    while(Que.size())
    {
        Edge Now=Que.top();Que.pop();
        int u=Now.Num;
        if(Vis[u])continue;
        Vis[u]=true;
        Ans=Ans+Now.Val;
        for(int i=G.Head[u];i!=-1;i=G.Next[i])
        {
            int v=G.To[i];
            long long w=G.Val[i];
            if(Vis[v])continue;
            Que.push({v,w});
        }
    }
    printf("%lld\n",Ans); 
	return 0;
 } 
