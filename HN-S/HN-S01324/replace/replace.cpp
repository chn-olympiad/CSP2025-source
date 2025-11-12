#include<bits/stdc++.h>
using namespace std;
#define uint unsigned long long 

const int N=4e5+5,M=5e6+5;
const uint bas=616997;
int n,q,tot;
uint bp[M<<1],hs[M];
unordered_map<uint,int>mp,mpp;
vector<int>lenl[N],lenr[N];
unordered_map<uint,bool>visl,visr;

inline uint HS(string s)
{
	uint val=0;
	for(char ch:s)
		val=val*bas+ch;
	return val;
}

inline uint get_Hash(int lt,int rt)
{
	return hs[rt]-hs[lt-1]*bp[rt-lt+1];
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	bp[0]=1;
	for(int i=1;i<=(int)(1e7)+5;i++)
		bp[i]=bp[i-1]*bas;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		if(s==t)
			continue;
		int lt=-1;
		while(lt+1<s.size()&&s[lt+1]==t[lt+1])
			lt++;
		int rt=s.size();
		while(rt-1>=0&&s[rt-1]==t[rt-1])
			rt--;
		string ll="",rr="";
		if(lt!=-1)
			ll=s.substr(0,lt+1);
		if(rt!=s.size())
			rr=s.substr(rt);
		string st=ll+"&"+rr;
		string sst=s.substr(lt+1,rt-lt-1),stt=t.substr(lt+1,rt-lt-1);
		string sstt=sst+"#"+stt;
		uint tmp=HS(sstt);
		if(mp[tmp]==0)
			mp[tmp]=++tot;
		if(visl[mp[tmp]*(int)(1e7)+ll.size()]==false)
		{
			lenl[mp[tmp]].push_back(ll.size());
			visl[mp[tmp]*(int)(1e7)+ll.size()]=true;
		}
		tmp=HS(ll+"*"+sstt);
		if(mp[tmp]==0)
			mp[tmp]=++tot;
		if(visr[mp[tmp]*(int)(1e7)+rr.size()]==false)
		{
			lenr[mp[tmp]].push_back(rr.size());
			visr[mp[tmp]*(int)(1e7)+rr.size()]=true;
		}
		mpp[HS(ll+"*"+sstt+"!"+rr)]++;
	}
	while(q--)
	{
		string s,t;
		int ans=0;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<"0\n";
			continue;
		}
		int lt=-1;
		while(lt+1<s.size()&&s[lt+1]==t[lt+1])
			lt++;
		int rt=s.size();
		while(rt-1>=0&&s[rt-1]==t[rt-1])
			rt--;
		string ll="",rr="";
		if(lt!=-1)
			ll=s.substr(0,lt+1);
		if(rt!=s.size())
			rr=s.substr(rt);
		string st=ll+"&"+rr;
		string sst=s.substr(lt+1,rt-lt-1),stt=t.substr(lt+1,rt-lt-1);
		string sstt=sst+"#"+stt;
		uint tmp=HS(sstt);
		if(mp[tmp]==0)
		{
			cout<<"0\n";
			continue;
		}
		hs[0]=s[0];
		for(int i=1;i<s.size();i++)
			hs[i]=hs[i-1]*bas+s[i];
		for(int len:lenl[mp[tmp]])
		{
			if(lt-len+1<0)
				continue;
			uint ttmp=get_Hash(lt-len+1,lt)*bp[sstt.size()+1ull]+(uint)('*')*bp[sstt.size()]+tmp;
			for(int llen:lenr[mp[ttmp]])
			{
				if(rt+llen-1>=s.size())
					continue;
				uint tttmp=ttmp*bp[llen+1]+(uint)('!')*bp[llen]+get_Hash(rt,rt+llen-1);
				ans+=mpp[tttmp];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
