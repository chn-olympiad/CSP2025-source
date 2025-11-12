#include<bits/stdc++.h>
#define int long long
using namespace std;
const size_t aph=13331;
const int cxk=5e6+5;
size_t ss[cxk],tt[cxk],hx[cxk],hy[cxk],pw[cxk];
int xx,yy,n,m;
string s[cxk],t[cxk],x,y;
map<size_t,size_t>mp;
size_t qx(int lt,int rt)
{
	return hx[rt]-hx[lt-1]*pw[rt-lt+1];
}
void help()
{
	int cnt=0;
	cin>>x>>y;
	xx=x.size(),yy=y.size();
	if(xx!=yy)
	{
		cout<<"0\n";
		return;
	}
	x=' '+x;
	y=' '+y;
	pw[0]=1;
	for(int i=1;i<=xx;i++)
	{
		hx[i]=hx[i-1]*aph+x[i];
		pw[i]=pw[i-1]*aph;
	}
	for(int i=1;i<=yy;i++)
		hy[i]=hy[i-1]*aph+y[i];
	for(int i=1;i<=xx;i++)
		for(int j=i;j<=xx;j++)
			if(mp[qx(i,j)]&&hx[xx]-(qx(i,j)-mp[qx(i,j)])*pw[xx-j]==hy[yy])
				cnt++;
	cout<<cnt<<"\n";
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
		for(char c:s[i])
			ss[i]=ss[i]*aph+c;
		for(char c:t[i])
			tt[i]=tt[i]*aph+c;
		mp[ss[i]]=tt[i];
	}
	for(;m--;help());
	return 0;
}
/*
4 2 
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


*/

