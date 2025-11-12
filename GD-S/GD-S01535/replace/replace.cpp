#include<bits/stdc++.h>
using namespace std;
bool st;
int n,Q;
namespace sub{
	const int N=2e6+88;
	bool pre[N],suf[N];
	struct trie{
		int tr[N][26];
		int dir=0;
		map<int,bool>u[N];
		void insert(string x,int bh)
		{
			int len=x.size();
			int nw=0;
			for(int i=0;i<len;i++)
			{
				int ch=x[i]-'a';
				if(!tr[nw][ch]) tr[nw][ch]=++dir;
				nw=tr[nw][ch];
			}
			u[nw][bh]=1;
		}
	}T1,T2;
	string t1,t2;
	void mainn()
	{
		for(int i=1;i<=n;i++)
		{
			cin>>t1;
			cin>>t2;
			T1.insert(t1,i);
			T2.insert(t2,i);
		}
		while(Q--)
		{
			cin>>t1>>t2;
			int len=t1.size(),ans=0;
			for(int i=0;i<=len;i++) pre[i]=0,suf[i]=0;
			pre[0]=suf[len+1]=1;
			for(int i=1;i<=len;i++) pre[i]=pre[i-1]&(t1[i-1]==t2[i-1]);
			for(int i=len;i>=1;i--) suf[i]=suf[i+1]&(t1[i-1]==t2[i-1]);
			for(int i=1;i<=len;i++)
			{
				int nw1=0,nw2=0;
				if(!pre[i-1]) break;
				for(int j=i;j<=len;j++)
				{
					int ch1=t1[j-1]-'a',ch2=t2[j-1]-'a';
					if(!T1.tr[nw1][ch1]||!T2.tr[nw2][ch2]) break;
					nw1=T1.tr[nw1][ch1],nw2=T2.tr[nw2][ch2];
					if(!suf[j+1]) continue;
					for(auto k:T1.u[nw1]) ans+=T2.u[nw2][k.first];
				}
			}
			printf("%d\n",ans);
			//cout<<ans<<"\n";
		}
	}
}
bool ed;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cerr<<(&st-&ed)/1048576.0000<<"\n";
	cin>>n>>Q;
	sub::mainn();
}
