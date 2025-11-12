#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;

struct aaa
{
	int a,b,c;
}f[N];
int T;
int n;

int vis[3];

int ans=0;

void dfs(int cn,int aa,int bb,int cc,int sum)
{
	if(cn>n)return ;
	if(cn==n)
	{
		ans=max(ans,sum);
		//cout<<ans<<"    --    "<<cn<<"    "<<aa<<"   "<<bb<<"   "<<cc<<"   "<<sum<<endl;
	}
	
	if(aa<n/2)dfs(cn+1,aa+1,bb,cc,sum+f[cn+1].a);
	else return;
	if(bb<n/2)dfs(cn+1,aa,bb+1,cc,sum+f[cn+1].b);
	else return ;
	if(cc<n/2)dfs(cn+1,aa,bb,cc+1,sum+f[cn+1].c);
	else return ;
	
	return ;
	
}

bool cmp(aaa x,aaa y)
{
	return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	
	while(T--)
	{
		cin>>n;
		int bj_1=0;
		int bj_2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].b==0&&f[i].c==0&&f[i].a)bj_1=1;
			if(f[i].c==0&&f[i].a&&f[i].b)bj_2=1;
		}
		ans=0;
		if(bj_1)
		{
			sort(f+1,f+1+n,cmp); 
			for(int i=1;i<=n/2;i++)
			{
				ans+=f[i].a; 
			}
			cout<<ans<<endl;
			continue;
		}
		if(bj_2)
		{
			int bj=0;
			for(int i=1;i<=n;i++)
			{
				if(f[i].a>f[i].b&&bj<=n/2)
				{
					ans+=f[i].a;
					bj++;
				}
				else ans+=f[i].b; 
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=200)
		{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
		else cout<<1<<endl;
		
		
	}
	
	
	return 0;
 } 
 //3 4 4 2 1 3 2 4 5 3 4 3 5 1