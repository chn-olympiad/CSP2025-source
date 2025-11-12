#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],yhx[260][260];
int maxn;
bool yhp[260][260];
string to10_2(int x)
{
	string s="";
	if(x==0) return "0";
	while(x>0)
	{
		s=char(x%2+'0')+s;
		x/=2;
	}
	return s;
}
int to2_10(string s)
{
	int x=0;
	for(int j=0;j<s.size();++j)
		x+=int(s[j]-'0')*pow(2,s.size()-j-1);
	return x;
}
int YH(int x,int y)
{
	string sx=to10_2(x),sy=to10_2(y),sz="";
	if(sx.size()>sy.size())
		while(sy.size()<sx.size()) sy='0'+sy;
	else
		while(sy.size()>sx.size()) sx='0'+sx;
	for(int i=0;i<max(sx.size(),sy.size());++i)
	{
		int t=int(sy[i]-'0')+int(sx[i]-'0');
		sz+=char(t%2+'0');
	}
	while(sz[0]=='0') sz=sz.substr(1,sz.size()-1);
	return to2_10(sz);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			int h=a[i];
			for(int p=i+1;p<=j;++p)
			{
				if(yhp[h][a[p]]) h=yhx[h][a[p]];
				else
				{
					h=YH(h,a[p]);
					yhp[h][a[p]]=1;
					yhx[h][a[p]]=YH(h,a[p]);
				}
			}
			if(h==k)
			{
				maxn++;
				i=j+1;
			}
		}
	}
	cout<<maxn<<"\n";
    return 0;
}
