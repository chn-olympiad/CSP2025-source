#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2][200005],t[2][200005],t1,t2;
int len;
bool check(string s,string s1,int f)
{
	cout<<s<<" "<<s1<<" "<<f<<'\n';
	if(s.size()!=len) return 0;
	string ss=t1;
	for(int i=f-len+1;i<=f;i++)
	{
		if(s[i-(f-len+1)]!=ss[i]) return 0;
		ss[i]=s1[i-(f-len+1)];
	}
	if(ss==t2) return 1;
	return 0;
}
bool cheak(string s,string s1,int f)
{
	cout<<s<<" "<<s1<<" "<<f<<'\n';
	if(s.size()<len) return 0;
	int L=len;
	len=s.size();
	for(int i=max(1,f-len+1);i<=f-L+1;i++)
	{
		if(check(s,s1,i+len-1))
		{
			len=L;
			return 1;
		}
	}
	len=L;
	return 0;
}
vector<pair<int,int>> cnt[2000006];
const int e=1e6;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i];
	if(n<=100&&q<=100&&0)
	{
		while(q--)
		{
			len=0;
			int ans=0;
			cin>>t1>>t2;
			int l=t1.size();
			t1=" "+t1;
			t2=" "+t2;
			int f=0,F=0;
			for(int i=1;i<=l;i++)
			{
				if(t1[i]!=t2[i])
				{
					if(f) len=i-f+1;
					else f=i,len=1;
				}
			}
			f=f+len-1;
			if(F==1)
			{
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if(cheak(s[0][i],s[1][i],f)) ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int l=0,r=0;
		int si=s[0][i].size();
		for(int j=0;j<si;j++)
		{
			if(s[0][i][j]=='b') l=j;
		}
		for(int j=0;j<si;j++)
		{
			if(s[1][i][j]=='b') r=j;
		}
		cnt[l-r+e].push_back({si-l,r+1});
	}
	while(q--)
	{
		len=0;
		int ans=0;
		cin>>t1>>t2;
		int ll=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int f=0,F=0;
		int l=0,r=0;
		for(int i=1;i<=ll;i++)
		{
			if(t1[i]!=t2[i])
			{
				if(t1[i]=='b')
				{
					if(l){F=1;break;}
					l=i;
				}
				if(t2[i]=='b')
				{
					if(r){F=1;break;}
					r=i;
				}
				if(f) len=i-f+1;
				else f=i,len=1;
			}
		}
		f=f+len-1;
		if(F==1)
		{
			cout<<0<<'\n';
			continue;
		}
		while(t1[f-len]=='a') len++;
		int maxl=f-l+1;
		int maxr=r-(f-len+1)+1;
		for(auto j:cnt[l-r+e])
		{
			if(j.first<=maxl&&j.second<=maxr){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
