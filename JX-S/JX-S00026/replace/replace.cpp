#include<bits/stdc++.h>//set_baozha
using namespace std;
struct oo{
	int id,k;
	bool operator < (const oo &a) const {
		if(id==a.id) return k<a.k;
		return id<a.id;
	}
};
set<oo> l[27][27];
string op[1000010];
int main()
{
	freopen("replace3.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int i,j;
	int n,Q;
	cin>>n>>Q;
	for(i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		for(j=0;j<(int)(a.size());j++)
		{
			l[(int)(a[j]-'a')][(int)(b[j]-'a')].insert({i,j});
		}
		op[i]=a;
	}
	while(Q--)
	{
		queue<oo> q[2];
		string a,b;
		cin>>a>>b;
		int bj=0;
		int x=0,y=1;
		int st=n,ed=0;
		for(j=0;j<(int)(a.size());j++)
		{
			if(a[j]!=b[j]) ed=j,st=min(st,j);
		}
		for(j=st;j<=ed;j++)
		{
			if(bj==0)
			{
				bj=1;
				for(oo t:l[a[j]-'a'][b[j]-'a']) q[x].push(t);
			}
			else if(bj==1)
			{
				while(!q[y].empty())
				{
					oo nw;
					nw=q[y].front();
					q[y].pop();
					if(l[a[j]-'a'][b[j]-'a'].count({nw.id,nw.k+1})>0) q[x].push({nw.id,nw.k+1});
				}
			}
			swap(x,y);
		}
		int da=0;
		while(!q[y].empty())
		{
			oo nw;
			nw=q[y].front();
			q[y].pop();
			int bj=0;
			for(i=ed-nw.k;i<ed-nw.k+(int)(op[nw.id].size());i++)
			{
				if(a[i]!=op[nw.id][i-ed+nw.k])
				{
					bj=1;
					break;
				}
			}
			if(bj==0) da++;
		}
		cout<<da<<"\n";
	}
}
