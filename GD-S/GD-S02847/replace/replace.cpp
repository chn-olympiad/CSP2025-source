#include<bits/stdc++.h>
using namespace std;

int n,q,len[210];
vector<int> g[400010];
unsigned long long p[210],ht[2][210],hs[210][2];
string s1,s2;

unsigned long long to_hash(string S)
{
	unsigned long long sumx=0;
	for(int i=0;i<S.size();i++) sumx=sumx*131+S[i];
	return sumx;
}
unsigned long long get_hash(int l,int r,unsigned long long h[])
{
	if(l>r) return 0;
	return h[r]-h[l-1]*p[r-l+1];
}
unsigned long long add_hash(unsigned long long x,unsigned long long y,int leny)
{
	return x*p[leny]+y;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n<=100 && q<=100)
	{
		p[0]=1;
		for(int i=1;i<=200;i++) p[i]=p[i-1]*131;
		for(int i=1;i<=n;i++)
		{
			cin>>s1>>s2;
			hs[i][0]=to_hash(s1);len[i]=s1.size();
			hs[i][1]=to_hash(s2);
		}
		while(q--)
		{
			cin>>s1>>s2;
			for(int i=1;i<=s1.size();i++)
				ht[0][i]=ht[0][i-1]*131+s1[i-1];
			for(int i=1;i<=s1.size();i++)
				ht[1][i]=ht[1][i-1]*131+s2[i-1];
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j+len[i]-1<=s1.size();j++)
				{
					if(get_hash(j,j+len[i]-1,ht[0])!=hs[i][0]) continue;
					unsigned long long tmp=ht[0][j-1];
					tmp=add_hash(tmp,hs[i][1],len[i]);
					tmp=add_hash(tmp,get_hash(j+len[i],n,ht[0]),n-j-len[i]+1);
					if(tmp==ht[1][s1.size()]) ans++;
				}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int pos1=s1.find('b');
		int pos2=s2.find('b');
		int x=max(pos1,pos2),y=pos1-pos2;
		g[y+200000].push_back(x);
	}
	for(int i=0;i<=4e5;i++) sort(g[i].begin(),g[i].end());
	while(q--)
	{
		cin>>s1>>s2;
		int pos1=s1.find('b');
		int pos2=s2.find('b');
		int x=max(pos1,pos2),y=pos1-pos2+200000;
		if(g[y].size()==0)
		{
			cout<<0<<endl;
			continue;
		}
		int l=0,r=g[y].size()-1;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(g[y][mid]>x) r=mid-1;
			else l=mid;
		}
		cout<<l+1<<endl;
	}
	return 0;
}
