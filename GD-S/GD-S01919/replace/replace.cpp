#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
const ull base=133331;
int n,q;
string s[2][N];
string s2[2][N];
unordered_map<ull,int> mp,mp2;
int cnt1,cnt2;
ull hash1[2][N],hash2[2][N];
ull hs(string s)
{
	if(!s.size())return 0;
	ull ans=0;
	for(int i=0;i<s.size();i++)ans=(ans*base+(ull)(s[i]-'a'));
	return ans;
}
ull hs2(string s)
{
	if(!s.size())return 0;
	ull ans=0;
	for(int i=s.size()-1;i>=0;i--)ans=(ans*base+(ull)(s[i]-'a'));
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[0][i]>>s[1][i];
	for(int i=1;i<=n;i++)
	{
		int siz=s[0][i].size();
		int l=-1,r=-1;
		for(int j=0;j<siz;j++)
		{
			if(s[0][i][j]!=s[1][i][j])
			{
				l=j;
				break;
			}
		}
		for(int j=siz-1;j>=0;j--)
		{
			if(s[0][i][j]!=s[1][i][j])
			{
				r=j;
				break; 
			}
		}
		if(l==r&&l==-1)continue;
	//	cout<<l<<' '<<r<<'\n';
	//	cout<<s[0][4]<<' '<<s[1][4]<<'\n';
		s2[0][i]=s[0][i].substr(l,r-l+1);
		s2[1][i]=s[1][i].substr(l,r-l+1);
	//	cout<<s2[0][i]<<' '<<s2[1][i]<<'\n';
		string s3=s[0][i].substr(0,l);
		string s4=s[0][i].substr(r+1,siz-r-1);
		hash1[0][i]=hs(s2[0][i]);
		hash1[1][i]=hs(s2[1][i]);
		hash2[0][i]=hs2(s3);
		hash2[1][i]=hs(s4);
	//	mp[s3+"#"+s2[0][i]+"&"+s2[1][i]]=++cnt1;
	//	mp2[s4+"#"+s2[0][i]+"&"+s2[1][i]]=++cnt2;
	//	bt1[cnt1].set(i);
	//	bt2[cnt2].set(i);
//	cout<<s3<<' '<<s4<<'\n';
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int siz=t1.size();
		int l=0,r=0;
		for(int j=0;j<siz;j++)
		{
			if(t1[j]!=t2[j])
			{
				l=j;
				break;
			}
		}
		for(int j=siz-1;j>=0;j--)
		{
			if(t1[j]!=t2[j])
			{
				r=j;
				break; 
			}
		}
		string T1=t1.substr(l,r-l+1);
		string T2=t2.substr(l,r-l+1);
		string T3=t1.substr(0,l);
		string T4=t1.substr(r+1,siz-r-1);
		ull h1=hs(T1);
		ull h2=hs(T2);
		ull now=0;
		mp.clear(),mp2.clear();
		mp[0]++;
		if(T3.size())
		{
			for(int j=T3.size()-1;j>=0;j--)
			{
				now=(now*base+(ull)(T3[j]-'a'));
				mp[now]++;
			}
		}
		now=0;
		mp2[0]++;
		for(int j=0;j<T4.size();j++)
		{
			now=(now*base+(ull)(T4[j]-'a'));
			mp2[now]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(hash1[0][i]==h1&&hash1[1][i]==h2&&mp[hash2[0][i]]&&mp2[hash2[1][i]])ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
