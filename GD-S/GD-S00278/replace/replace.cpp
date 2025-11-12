#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5,c=37,mod=1e9+7;
int n,q,cnt,tf[N],te[N];
long long hs1[M],hs[M];
string s1[N],s2[N],ts1,ts2;
map<pair<string,string>,int> m;
vector<int> v[N];
long long qm(long long x,int y)
{
	long long ans=1;
	while(y>0)
	{
		if(y%2==1) ans=(ans*x)%mod;
		x=(x*x)%mod,y>>=1;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(register int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
		tf[i]=-1,te[i]=-1;
		for(register int j=0;j<s1[i].size();++j)
		{
			if(j==0) hs[i]=(s1[i][j]-'a');
			else hs[i]=(hs[i]*c%mod+(s1[i][j]-'a'))%mod;
			if(s1[i][j]!=s2[i][j])
			{
				if(tf[i]==-1) tf[i]=j;
				te[i]=j;
			}
		}
		ts1="",ts2="";
		for(register int j=tf[i];j<=te[i];++j) 
			ts1+=s1[i][j],ts2+=s2[i][j];
		pair<string,string> now=make_pair(ts1,ts2);
		if(m[now]==0) cnt++,m[now]=cnt;
		int w=m[now];
		v[w].push_back(i);
	}
	for(register int i=1;i<=q;++i)
	{
		string t1,t2;
		cin>>t1>>t2;
		int f1=-1,f2=-1;
		for(register int j=0;j<t1.size();j++)
		{
			if(j==0) hs1[j]=(t1[j]-'a');
			else hs1[j]=(hs1[j-1]*c%mod+(t1[j]-'a'))%mod;
			if(t1[j]!=t2[j])
			{
				if(f1==-1) f1=j;
				f2=j;
			}
		}
		ts1="",ts2="";
		for(register int j=f1;j<=f2;++j)
			ts1+=t1[j],ts2+=t2[j];
		int w=m[make_pair(ts1,ts2)];
		if(w==0) { cout<<"0\n"; continue; }
		int ans=0;
		for(register int j=0;j<v[w].size();++j)
		{
			int now=v[w][j];
			int fst=f1-tf[now],ed=fst+s1[now].size()-1;
			if(fst<0||ed>=t1.size()) continue;
			long long x;
			if(fst!=0) x=(hs1[fst-1]*qm(c,s1[now].size())%mod+hs[now])%mod;
			else x=hs[now];
			if(x==hs1[ed]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
