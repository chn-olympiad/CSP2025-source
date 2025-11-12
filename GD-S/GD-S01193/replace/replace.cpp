#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,vector<string> > mp;
map<string,bool> bz;
int n,q,ans,l=-1,r,ly;
string x,y,f,s;
void mian()
{
	ans=0,l=r=-1;
	cin>>x>>y;
	if(x.size()!=y.size())
	{
		printf("0\n");
		return ;
	}
	ly=y.size();
	for(int i=0;i<ly;i++)
	{
		if(y[i]!=x[i])
		{
			if(l==-1) l=i;
			r=i;
		}
	}
	for(int i=l;i>=0;i--)
	{
		f=s="";
		for(int j=i;j<r;j++) f+=y[j],s+=x[j];
		for(int j=r;j<ly;j++)
		{
			f+=y[j],s+=x[j];
			if(!bz[f]) continue;
			for(string o : mp[f])
			{
				if(o==s) ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		bz[y]=1,mp[y].push_back(x);
	}
	while(q--) mian();
	return 0;
}
