#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,M=2e5+5;
int n,q,bj[N],po,o,ac[N*2+5][28],lst[N*2+5],siz2[N*2+5],sum[N],top,po1[M],siz[M],top1,mn,mx;
string a,b,c[M],d,e;
void bd()
{
	int sum1=n;
	for(int j=0;j<mx;++j)
	{
		top1=0;
		for(int z=1;z<=sum1;++z)
		{
			int now=po1[z];
			if(c[z][j]=='|')
			{
				if(!ac[now][27])
				{
					++o;
					ac[now][27]=o;
					int po=lst[now];
					while(po&&!ac[po][27]) po=lst[po];
					if(ac[po][27]) lst[o]=ac[po][27];
					else lst[o]=po;
					sum[o]=sum[lst[o]];
				}
				now=ac[now][27];
			}
			else{
				if(!ac[now][c[z][j]-'a'])
				{
					++o;
					ac[now][c[z][j]-'a']=o;
					int po=lst[now];
					while(po&&!ac[po][c[z][j]-'a']) po=lst[po];
					if(ac[po][c[z][j]-'a']) lst[o]=ac[po][c[z][j]-'a'];
					else lst[o]=po;
					sum[o]=sum[lst[o]];
				}
				now=ac[now][c[z][j]-'a'];
			}
			siz2[now]=j+1;
			if(j==0) lst[now]=0;
			po1[z]=now;
			if(j==siz[z]-1) ++sum[now];
			else ++top1,c[top1]=c[z],siz[top1]=siz[z],po1[top1]=po1[z];
		}
		sum1=top1;
	}
}
int find(string x,int p)
{
	int now=0,ans=0;
	for(int i=0;i<p;++i)
	{
		if(x[i]=='|')
		{
			if(!ac[now][27]) {
				while(now&&!ac[now][27]) now=lst[now];
				if(ac[now][27]) now=ac[now][27];
			}
			else
				now=ac[now][27];
		}
		else{
			if(!ac[now][x[i]-'a']){
				while(now&&!ac[now][x[i]-'a']) now=lst[now];
				if(ac[now][x[i]-'a']) now=ac[now][x[i]-'a'];
			}
			else
				now=ac[now][x[i]-'a'];
		}
		if(i>=mx&&i-siz2[now]+1<=mn) ans+=sum[now];
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b;
		po=a.size();
		for(int j=0;j<po*3;++j) c[i]+=' ';
		for(int j=0;j<po;++j)
		{
			c[i][j*3]=a[j];
			c[i][j*3+1]='|';
			c[i][j*3+2]=b[j];
		}
		siz[i]=po*3;
		mx=max(mx,po*3);
	}
	bd();
	for(int i=1;i<=q;++i)
	{
		cin>>a>>b;
		d=e;
		if(a.size()!=b.size())
		{
			cout<<0<<'\n';
			continue;
		}
		po=a.size();
		for(int j=0;j<po;++j)
		{
			if(a[j]==b[j]) bj[j]=1;
			else 
			{
				mn=j*3;
				break;
			}
		}
		for(int j=po-1;j>=0;--j)
		{
			if(a[j]==b[j]) bj[j]=1;
			else 
			{
				mx=(j+1)*3-1;
				break;
			}
		}
//		cout<<mn<<" "<<mx<<" ";
		for(int j=0;j<po*3;++j) d+=' ';
		for(int j=0;j<po;++j)
		{
			d[j*3]=a[j];
			d[j*3+1]='|';
			d[j*3+2]=b[j];
		}
		cout<<find(d,po*3)<<'\n';
	}
	return 0;
 } 
