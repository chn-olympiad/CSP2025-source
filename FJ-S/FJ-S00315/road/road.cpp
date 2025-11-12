#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+15;
struct d
{
	int u,v,w;
}e[MAXN];

int f[MAXN] = {0};
int find(int x)
{
	if(f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void me(int x,int y)
{
	f[find(x)] = find(y);
	return ;
}

bool cmp(d x,d y)
{
	return x.w < y.w;
}

inline int read()
{
	int res = 0;
	char c = getchar();
	while(c >= '0' && c <= '9')
	{
		res *= 10;
		res += c-'0';
		c = getchar();
	}
	return res;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//read();
	int n,m,k;
	cin>>n>>m>>k;
	read();
	for(int i = 0;i < m;i++) e[i].u = read(),e[i].v = read(),e[i].w = read();
	
	
	for(int i = 0;i < k;i++)
	{
		int t;
		cin>>t;
		for(int j = 1;j <= n;j++)
		{
			int w;
			scanf("%d",&w);
			e[m+i*n+j].u = m+i+1,e[m+i*n+j].v = j,e[m+i*n+j].w = w;
		}
	}
	//cout<<123<<endl;
	for(int i = 0;i < MAXN;i++) f[i] = i;
	
	
	//cout<<123<<endl;
	sort(e,e+m+k*n,cmp);
	//for(int i = 0;i < 20;i++) printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
	long long cost = 0;
	//cout<<123<<endl;
	
	for(int i = 0;i < m+k;i++)
	{
		if(find(e[i].u) != find(e[i].v)) 
		{
			//cout<<find(e[i].u)<<" "<<find(e[i].v)<<endl;;
			me(e[i].u,e[i].v);
			cost += e[i].w;
		}
	}
	cout<<cost;
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
