#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;

const int N=2e5+5;

int n,q,id[N];

string s1[N],s2[N],t1,t2;

bool cmp(int x,int y)
{
	return s1[x].size()<s1[y].size();
}

bool check(int l,int r)
{
	string res1=t1.substr(l,r-l+1);
	string res2=t2.substr(l,r-l+1);
	_rep(o,1,n)
	{
		int i=id[o];
		if(s1[i].size()>res1.size()) break;
		if(s1[i].size()==res1.size()) 
			if(s1[i]==res1&&s2[i]==res2) 
				return true; 
	}
	return false;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	_rep(i,1,n) cin>>s1[i]>>s2[i],id[i]=i; 
	
	sort(id+1,id+n+1,cmp);
	
	while(q--)
	{ 
		cin>>t1>>t2;
		
		int len=t1.size(),fir=0,sec=0;
		
		_rep(i,0,len-1)
		{
			if(t1[i]!=t2[i]) 
			{
				fir=i;
				break;
			}
		}
		
		_antirep(i,len-1,0)
		{
			if(t1[i]!=t2[i])
			{
				sec=i;
				break;
			}
		} 
		
		int ans=0;
		_rep(l,0,fir)
			_rep(r,sec,len-1)
				if(check(l,r)) ans++;
				
		cout<<ans<<"\n";
	}
	
	return 0;
}
