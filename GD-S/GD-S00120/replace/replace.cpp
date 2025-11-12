#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int>xx;
set<pair<int,pair<int,int> > >yy[200005];
string a[200005],b[200005],x,y,xaz,yaz;
int n,q,tot,tott;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;for(int nn=1;nn<=n;nn++)
	{
		cin>>a[nn]>>b[nn];
		int siz=a[nn].size();
		int i=0,j=siz-1;while(1)
		{
			if(i>j) break;
			if(a[nn][i]!=b[nn][i]
			&&a[nn][j]!=b[nn][j]) break;
			if(a[nn][i]==b[nn][i]) i++;
			if(a[nn][j]==b[nn][j]) j--;
		}x.clear(),y.clear();
		if(i>j) continue;
		for(int k=i;k<=j;k++)
		x+=a[nn][k],y+=b[nn][k];
		if(!xx.count({x,y}))
		xx[{x,y}]=++tot;
		yy[xx[{x,y}]].insert({nn,{i,j}});
	}while(q--)
	{
		cin>>xaz>>yaz;
		if(xaz.size()!=yaz.size())
		{cout<<0<<'\n';continue;}
		int siz=xaz.size();
		int i=0,j=siz-1;while(1)
		{
			if(i>j) break;
			if(xaz[i]!=yaz[i]
			&&xaz[j]!=yaz[j]) break;
			if(xaz[i]==yaz[i]) i++;
			if(xaz[j]==yaz[j]) j--;
		}x.clear(),y.clear();
		for(int k=i;k<=j;k++)
		x+=xaz[k],y+=yaz[k];
		if(!xx.count({x,y}))
		{cout<<0<<'\n';continue;}
		int num=xx[{x,y}],ans=0;
		for(auto z:yy[num])
		{
			int ii=z.second.first,jj=z.second.second,wh=z.first;
			int len=a[wh].size(),ix=i,jx=j;
			if(ii+1>ix+1||len-jj>siz-jx) continue;
			for(;ii>=0;ix--,ii--)
			if(a[wh][ii]!=xaz[ix]) break;
			for(;jj<len;jx++,jj++)
			if(b[wh][jj]!=yaz[jx]) break;
			if(ii<0&&jj==len) ans++;
		}cout<<ans<<'\n';
	}
}
