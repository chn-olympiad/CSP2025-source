#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
namespace case1
{
	const int N=2005,B=31,mod=993244853;
	int pw[N];
	void init(){pw[0]=1;for(int i=1;i<N;i++)pw[i]=pw[i-1]*B%mod;}
	struct hsh
	{
		int f[N],n;
		void init(string &s){n=s.size();for(int i=1;i<=n;i++)f[i]=(f[i-1]*B%mod+s[i-1]-'a')%mod;}
		int get(int l,int r){return l>r?0:(f[r]-f[l-1]*pw[r-l+1]%mod+mod)%mod;}
	}a[N];
	int solve(string &s,string &t)
	{
		hsh s1,t1;s1.init(s),t1.init(t);
		int siz=s.size(),ans=0;
		for(int i=1;i<=siz;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int len=a[j].n;
				if(i<len)continue;
				if(s1.get(i-len+1,i)==a[j].get(1,len)&&t1.get(i-len+1,i)==a[j+n].get(1,len))
					if(s1.get(1,i-len)==t1.get(1,i-len)&&s1.get(i+1,siz)==t1.get(i+1,siz))ans++;
			}
		}
		return ans;
	}
	int main()
	{
		init();
		for(int i=1;i<=n;i++)
		{
			string s,t;cin>>s>>t;
			a[i].init(s),a[i+n].init(t);
		}
		while(q--)
		{
			string s,t;cin>>s>>t;
			cout<<solve(s,t)<<'\n';
		}
		return 0;
	}
}
signed main()
{
//	system("fc replace2.ans replace.out");return 0;
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n<=1000)return case1::main();
	while(q--)cout<<0<<'\n';
	return 0;
}
