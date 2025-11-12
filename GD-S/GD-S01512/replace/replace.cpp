#include<iostream>//road 最小生成树 prim
#include<algorithm>
#include<cstring>
#include<queue>
#define PII pair<int,int>
using namespace std;
const int N=5e6+10,M=1e4+50;
string a[N],b[N];
int n,m,t,t1;
string s,s1;
bool pei(int x,int y)
{
	for(int i=0;i<a[y].size();x++,i++)
		if(a[y][i]!=s[x])
			return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(m--)
	{
		long long sum=0;
		cin>>s>>s1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s.size();j++)
			{
				if(pei(j,i))
				{
					string pp=s;
					for(int k=j,o=0;o<a[i].size();o++,k++)
						pp[k]=b[i][o];
					if(pp==s1)
						sum++;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
