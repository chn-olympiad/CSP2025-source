#include<bits/stdc++.h>
using namespace std;
long long use[1000010],f[1000010],n,t,m,k,ans[11],maxn,tmp,u,w,co;
struct asd{
	int be,en,c;
}b[1000010];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(asd x,asd y)
{
	return x.c<y.c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].be>>b[i].en>>b[i].c;
		
	}
	sort(b+1,b+m+1,cmp);t=0;
	for(int i=1;i<=m;i++)
	{
		int l=find(b[i].be),r=find(b[i].en);
		if(f[l]!=f[r]){
			f[b[i].be]=find(b[i].en);ans[0]+=b[i].c;
	}
}

	

for(int i=1;i<=k;i++)
	{
		cin>>tmp;
		for(int j=1;j<=n;j++)
		{
			cin>>co;
			
		}
	}
	cout<<ans[0];
	return 0;
} 
