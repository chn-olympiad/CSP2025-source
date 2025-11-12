#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int unsigned long long
using namespace std;
const int N=200020;
int p131[5000020];
int gethash(string s)
{
	int res=0,len=s.size();
	fo(i,0,len-1)res+=(s[i])*p131[len-1-i];
	return res;
}
map<int,vector<int> > mp;
int n,q;
vector<int> cd;
map<int,bool> lmp;
char c;
string read()
{
	string s="";
	while(c==' '||c=='\n')c=getchar();
	while(c!=' '&&c!='\n')s+=c,c=getchar();
	return s;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;c=getchar();
	p131[0]=1;
	fo(i,1,5000000)p131[i]=p131[i-1]*(int)131;
	fo(i,1,n)
	{
		string x=read(),y=read();
		if(!lmp.count((int)x.size()))
		{
			cd.push_back((int)x.size());
			lmp[(int)x.size()]=1;
		}
		mp[gethash(x)].push_back(gethash(y));
	}
	
	while(q--)
	{
		string x=read(),y=read();
		int hx=gethash(x),hy=gethash(y);
		int ans=0;
		for(auto len:cd)
		{
			if(len>(int)x.size())break;
			int l=0,r=len-1,now=gethash(x.substr(0,len));
			while(r<(int)x.size())
			{
				if(mp.count(now))
					for(auto i:mp[now])
						ans+=(hx+(-now+i)*p131[(int)x.size()-1-r]==hy);
				if(r<(int)(x.size())-1)
					now=(now-(int)(x[l])*p131[len-1])*(int)131+(int)(x[r+1]);
				l++;r++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
