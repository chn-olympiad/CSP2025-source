#include<bits/stdc++.h>
#define ull unsigned long long
#define ui unsigned int
using namespace std;
const int N=1e6+7;
struct Hash
{
	const ull B1=131;
	const ui B2=97;
	ull fac1[N],F1[N];
	ui fac2[N],F2[N];
	Hash()
	{
		fac1[0]=1;
		fac2[0]=1;
		for(int i=1;i<N;i++)
		{
			fac1[i]=fac1[i-1]*B1;
			fac2[i]=fac2[i-1]*B2;
		}
	}
	inline void insert(string s)
	{
		int n=s.size();
		s=' '+s;
		for(int i=1;i<=n;i++)
		{
			F1[i]=F1[i-1]*B1+s[i]-'a'+1;
			F2[i]=F2[i-1]*B2+s[i]-'a'+1;
		}
	}
	inline pair<ull,ui> query(int l,int r)
	{
		return {F1[r]-F1[l-1]*fac1[r-l+1],F2[r]-F2[l-1]*fac2[r-l+1]};
	} 
}h1,h2,H1,H2;
int n,q;
string s1[N],s2[N];
int l[N];
map<pair<ull,ui>,int> mp;
map<pair<pair<ull,ui>,pair<ull,ui>>,int> mp2;
map<pair<int,int>,int> mp3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool sp=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int _a=0,_b=0;
		for(char s:s1[i])
		{
			if(s=='a') _a++;
			if(s=='b') _b++;
		}
		int len=s1[i].size();
		if(_a!=len-1||_b!=1)
			sp=0;
	}
	if(sp)
	{
		for(int i=1;i<=n;i++)
		{
			int len=s1[i].size();
			s1[i]=' '+s1[i];
			s2[i]=' '+s2[i];
			int L=0,R=0;
			for(int j=1;j<=len;j++)
			{
				if(s1[i][j]=='a')
					L++;
				else break;
			}
			for(int j=1;j<=len;j++)
			{
				if(s2[i][j]=='a')
					L--;
				else break;
			}
			for(int j=len;j>=1;j--)
			{
				if(s1[i][j]=='a')
					R++;
				else break;
			}
			for(int j=len;j>=1;j--)
			{
				if(s2[i][j]=='a')
					R--;
				else break;
			}
			mp3[{L,R}]++;
		}
		while(q--)
		{
			string t1;
			string t2;
			cin>>t1>>t2;
			int len=t1.size();
			t1=' '+t1;
			t2=' '+t2;
			int L=0,R=0;
			for(int j=1;j<=len;j++)
			{
				if(t1[j]=='a')
					L++;
				else break;
			}
			for(int j=1;j<=len;j++)
			{
				if(t2[j]=='a')
					L--;
				else break;
			}
			for(int j=len;j>=1;j--)
			{
				if(t1[j]=='a')
					R++;
				else break;
			}
			for(int j=len;j>=1;j--)
			{
				if(t2[j]=='a')
					R--;
				else break;
			}
			cout<<mp3[{L,R}]<<'\n';
		}
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		int len=s1[i].size();
		if(s1[i]==s2[i])
		{
			H1.insert(s1[i]);
			mp[H1.query(1,len)]++;
		}
		else
		{
			H1.insert(s1[i]);
			H2.insert(s2[i]);
			mp2[{H1.query(1,len),H2.query(1,len)}]++;
		}
	}
	while(q--)
	{
		string t1;
		string t2;
		cin>>t1>>t2;
		h1.insert(t1);
		h2.insert(t2);
		int len=t1.size();
		t1=' '+t1,t2=' '+t2;
		int id1=0;
		int id2=0;
		for(int i=1;i<=len;i++)if(t1[i]!=t2[i]){id1=i;break;}
		for(int i=len;i>=1;i--)if(t1[i]!=t2[i]){id2=i;break;}
		int res=0;
		if(!id1&&!id2)
		{
			for(int i=1;i<=len;i++)
			{
				for(int j=i;j<=len;j++)
				{
					auto dk=h1.query(i,j);
					if(mp.count(dk))
						res+=mp[dk];
				}
			}
			cout<<res<<'\n';
			continue;
		}
		for(int i=1;i<=id1;i++)
			for(int j=id2;j<=len;j++)
				if(mp2.count({h1.query(i,j),h2.query(i,j)}))
					res+=mp2[{h1.query(i,j),h2.query(i,j)}];
		cout<<res<<'\n';
	}
}
