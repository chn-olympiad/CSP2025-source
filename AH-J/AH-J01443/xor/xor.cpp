#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,p,cnt,ok=1,a[500005],k[25],f[25],vis[500005][25];
void work(int n,int id){
	if(id==0)
	{
		for(int i=n,j=0; j<=21; i/=2,j++)
			k[++cnt]=j,f[k[cnt]]=i%2;
		return;
	}
	for(int i=n,j=0; j<=21; i/=2,j++)
		vis[id][j]=vis[id-1][j]+i%2;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			ok=0;
	}
	if(ok)
	{
		
		cout<<n/2;
		return 0;
	}
	work(m,0);
	for(int i=1; i<=n; i++)
	{
		int ok=1;
		work(a[i],i);
		for(int j=1; j<=cnt; j++)
			if((vis[i][k[j]]-vis[p][k[j]])%2!=f[k[j]])
			{
				if(vis[i][k[j]]-vis[p][k[j]]<f[k[j]])
				{
					ok=0;
					break;
				}
				else
					ok=2;
			}
		if(ok==2)
		{
			for(int j=p+1; j<=i; j++)
			{
				int okk=1;
				for(int kk=1; kk<=cnt; kk++)
					if((vis[i][k[kk]]-vis[j-1][k[kk]])%2!=f[k[kk]])
					{
						okk=0;
						if(vis[i][k[kk]]-vis[j-1][k[kk]]<f[k[kk]])
							okk=-1;
					}
				if(okk==1)
				{
					ok=1;
					break;
				}
				if(okk==-1)
					break;
			}
		}
		if(ok==1)
			p=i,s++;
	}
	cout<<s;
    return 0;
}
