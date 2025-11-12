#include<bits/stdc++.h>
using namespace std;
long long n,m,k,np[12],popo[12][11000],a[11000];
struct node
{
	long long ayut,pro;
};
struct flord
{
	long long fro,toa,nom;
	bool operator < (const flord &alo)
	{
		return nom<alo.nom;
	} 
};
vector<node> aatt[11000];
priority_queue<flord> eop;
inline void mint()
{
	while(!eop.empty())
	{
		flord emt=eop.top();
		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	a[1]=0;
	for(int i=1;i<=m;i++)
	{
		long long tew,ope,faa;
		cin>>tew>>ope>>faa;
		aatt[tew].push_back({ope,faa});
		aatt[ope].push_back({tew,faa});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>np[i];
		for(int o=1;o<=n;o++)
		{
			cin>>popo[i][o];
		}
	}
	for(long long i=0;i<aatt[1].size();i++)
	{
		eop.push({1,aatt[1][i].ayut,aatt[1][i].pro});
	}
}
