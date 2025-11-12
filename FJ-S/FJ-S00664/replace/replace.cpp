#include<bits/stdc++.h>
using namespace std;
int a,b,tr[11000001][27],bs[200001],cs[11000001],fl[11000001],vis[11000001],l,r,p,s,out;
string c,d,e;
queue<int>ds;

struct rep
{
	string a,b;
}as[200001];

int nxt(int p,char c)
{
	if(!tr[p][c-'a'])tr[p][c-'a']=++s;
	return tr[p][c-'a'];
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>as[i].a>>as[i].b;
	}
	for(int i=1;i<=a;i++)
	{
		l=r=p=0;c="";
		for(int j=0;j<as[i].a.size();j++)
		{
			if(as[i].a[j]!=as[i].b[j])
			{
				if(!l)l=j+1;
				r=j+1;
			}
		}
		for(int j=l-1;j<r;j++)
		{
			p=nxt(p,as[i].a[j]);
		}
		p=nxt(p,'{'); 
		for(int j=l-1;j<r;j++)
		{
			p=nxt(p,as[i].b[j]);
		}
		p=nxt(p,'{');bs[i]=p;
		for(int j=0;j<l-1;j++)
		{
			p=nxt(p,as[i].a[j]);
		}
		p=nxt(p,'{');
		for(int j=r;j<as[i].a.size();j++)
		{
			p=nxt(p,as[i].a[j]);
		}
		cs[p]++;
	}
	for(int i=1;i<=a;i++)
	{
		p=bs[i];fl[p]=p;
		for(int j=0;j<27;j++)
		{
			if(!tr[p][j])tr[p][j]=p;
		}
		if(!vis[p])
		{
			vis[p]=1;ds.push(p);
			for(;ds.size();)
			{
				int q=ds.front();ds.pop();
				for(int j=0;j<27;j++)
				{
					if(!vis[tr[q][j]])
					{
						vis[tr[q][j]]=1;
						if(tr[fl[q]][j]!=tr[q][j])fl[tr[q][j]]=tr[fl[q]][j];
						else fl[tr[q][j]]=q;
						cs[tr[q][j]]+=cs[fl[tr[q][j]]];
						for(int k=0;k<27;k++)
						{
							if(!tr[tr[q][j]][k])tr[tr[q][j]][k]=tr[fl[tr[q][j]]][k];
						}
						ds.push(tr[q][j]); 
					}
				}
			}
		}
	}
	for(int i=1,can=1;i<=b;i++,can=1)
	{
		cin>>c>>d;l=r=p=out=0;e="";
		for(int j=0;j<c.size();j++)
		{
			if(c[j]!=d[j])
			{
				if(!l)l=j+1;
				r=j+1; 
			}
		}
		for(int j=l-1;j<r;j++)
		{
			p=tr[p][c[j]-'a'];
			if(!p)can=0;
		}
		p=tr[p][26];
		if(!p)can=0;
		for(int j=l-1;j<r;j++)
		{
			p=tr[p][d[j]-'a'];
			if(!p)can=0;
		}
		p=tr[p][26];
		if(!p)can=0;
		if(!can)
		{
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<l-1;j++)
		{
			p=tr[p][c[j]-'a'];
			out+=cs[p];
		}
		p=tr[p][26];out+=cs[p];
		for(int j=r;j<c.size();j++)
		{
			p=tr[p][c[j]-'a'];
			out+=cs[p];
		}
		cout<<out<<'\n';
	}
	return 0;
}
