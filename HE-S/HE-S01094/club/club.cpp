#include<bits/stdc++.h>
using namespace std;
#define Ifind {
#define Liujingyi
#define I 0
#define miss ;
#define you }
const int N=5e5+1000;
bool v[N];
struct more
{
	int ai;
	int aj;
	int va;
};
bool cp(more a,more b)
{
	return a.va>b.va;
}
int sum[5];
vector<more>s;
int T;
int main()
Ifind
	//也就是说针对于不同的n是不允许大于二分之一n；
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int k1,k2,k3;
			scanf("%d%d%d",&k1,&k2,&k3);
			s.push_back({i,1,k1});
			s.push_back({i,2,k2});
			s.push_back({i,3,k3});
			v[i]=1;//表示i成员可以选择； 
		}
		
		if(n==2)
		{
			 
		}
		
		int ans=0;
		int maxn=(n/2);
		sort(s.begin(),s.end(),cp);
		for(int i=0;i<s.size();i++)
		{
			int valo=s[i].va;
			int club_j=s[i].aj;
			int numb=s[i].ai;
			
			if(v[numb]==1 && sum[club_j]<maxn)
			{
				sum[club_j]++;
				ans+=valo;
				v[numb]=0;	
			}
		}
		printf("%d\n",ans);
		
		s.clear();
		for(int i=1;i<=3;i++)
		{
			sum[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			v[i]=1;
		}
    }
	Liujingyi I miss you
