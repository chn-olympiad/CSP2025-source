#include <bits/stdc++.h>
using namespace std;
int ds[510];
int naix[510];
int nenai[510];
int n,m;
int ps[510];
int ans=0;
void dfs(int p,int k,int fap)
{
//	if(p>n) cout<<ps[1]<<ps[2]<<ps[3]<<endl;
	if(p>n&&k>=m) 
	{
		ans++;
		ans%=998244353;
	}
	else for(int i=1;i<=n;i++)
	{
		bool abtd=1;
		for(int j=1;j<p;j++)
		{
			if(ps[j]==i)
			{
				abtd=0;
				break;
			}
		}
		if(abtd) 
		{
			int ofap=fap;
			int op=p;
			int ok=k;
			ps[p++]=i;
	//		cout<<naix[i]<<' '<<fap<<' '<<ds[p-1]<<' '<<k<<endl;
			if(naix[i]<=fap||ds[p-1]==0) fap++;
			else 
			{
				k++;
			}
			dfs(p,k,fap);
			fap=ofap;
			p=op;
			k=ok;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char tmp;
	
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		ds[i]=tmp-'0';
	}
	
	for(int i=1;i<=n;i++) 
	{
		cin>>naix[i];
	}
//	sort(naix+1,naix+1+n);
	int fangqi=0;
	int most=0;
	for(int i=1;i<=n;i++)
	{
		if(ds[i]==0) 
		{
			nenai[fangqi]++;
			most++;
			fangqi=0;
		}
		else fangqi++;
	}
	
	dfs(1,0,0);
	cout<<ans;
}
