#include<bits/stdc++.h>
#define BASE 1145141
#define N 200005
#define M 5000005
using namespace std;
int n,m,q,len[N],p1[N],p2[N],p3[N];
bool ok=1;
unsigned long long h1[N],h2[N],h3[M],h4[M],p[M];
string s,t;
unsigned long long Hash(unsigned long long h[],int l,int r){return h[r]-h[l-1]*p[r-l+1];}
map<int,vector<int> >v;
int check(string &s)
{
	int p=-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='a'&&s[i]!='b') return -1;
		if(s[i]=='b')
		{
			if(p==-1) p=i;
			else return -1;
		}	
	}
	return p+1;
}
void solve()
{
	int l=0,r=m-1,ans=0;
	while(s[l]==t[l]) l++;
	while(s[r]==t[r]) r--;
	l++,r++;
	for(int i=1;i<=m;i++) h3[i]=h3[i-1]*BASE+s[i-1]-'a'+1,h4[i]=h4[i-1]*BASE+t[i-1]-'a'+1;
	for(int i=1;i<=n;i++)
	{
		if(len[i]<r-l+1) continue;
		for(int j=max(1,r-len[i]+1);j<=min(m-len[i]+1,l);j++)
		{
			if(Hash(h3,j,j+len[i]-1)==h1[i]&&Hash(h4,j,j+len[i]-1)==h2[i]) ans++;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=5000000;i++) p[i]=p[i-1]*BASE;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		len[i]=s.size();
		for(int j=0;j<len[i];j++) h1[i]=h1[i]*BASE+s[j]-'a'+1,h2[i]=h2[i]*BASE+t[j]-'a'+1;
		p1[i]=check(s);
		p2[i]=check(t);
		if(p1[i]==-1||p2[i]==-1) ok=0;
//		cout<<i<<" "<<h1[i]<<" "<<h2[i]<<endl;
	}
	if(q==1) ok=0;
	if(ok)
	{
		for(int i=1;i<=n;i++)
		{
			v[p1[i]-p2[i]].push_back(i);
		}
	}
	while(q--)
	{
		cin>>s>>t;
		if(s.size()!=t.size()) {cout<<0<<"\n";continue;}
		m=s.size();
		int q1=check(s),q2=check(t),ans=0;
		if(q1==-1||q2==-1||ok==0) {solve();continue;}
//		cerr<<v[q1-q2].size()<<" "<<q1<<" "<<q2<<endl;
		for(int i:v[q1-q2])
		{
//			cout<<"[11] "<<p1[i]<<" "<<p2[i]<<" "<<len[i]-p1[i]<<endl;
			if(p1[i]-1<=q1-1&&len[i]-p1[i]<=m-q1&&p2[i]-1<=q2-1&&len[i]-p2[i]<=m-q2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

1 1
aaba abaa
aabaa abaaa
*/
