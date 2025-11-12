#include<bits/stdc++.h>
using namespace std;
const int maxs=5e6+5;
const int Mx=5e6+2;
const int maxn=2e5+5;
int c[maxs];
char s1[maxs],s2[maxs];
char t1[maxs],t2[maxs];
struct Node {string l,r; int id;};
vector<Node>a[maxn];
map<string,int>mp;
int cnt=0; int ans[maxn];
inline void works()
{
	scanf("%s %s",(s1+1),(s2+1));
	int len=strlen(s1+1);
	int l,r;
	for(l=1;l<=len;l++)
	{
		if(s1[l]!=s2[l]) break;
	}
	for(r=len;r>=1;r--)
	{
		if(s1[r]!=s2[r]) break;
	}
	if(l>r) return;
	string Str;
	for(int i=l;i<=r;i++) Str+=s1[i];
	for(int i=l;i<=r;i++) Str+=s2[i];
	if(mp[Str]==0) mp[Str]=++cnt;
	Node tmp; tmp.id=0;
	string L; L='a';
	for(int i=l-1;i>=1;i--) L+=s1[i];
	string R; R='a';
	for(int i=r+1;i<=len;i++) R+=s1[i];
	tmp.l=L; tmp.r=R;
//	cout<<L<<" "<<R<<" "<<(s1+1)<<" "<<(s2+1)<<" "<<Str<<"\n";
	a[mp[Str]].push_back(tmp);
	return;
}
inline bool Pre(string s,string t)
{
	if(s.size()>t.size()) return false;
	for(int i=0;i<s.size();i++)
		if(s[i]!=t[i]) return false;
	return true;
}
inline void workq(int Id)
{
	scanf("%s %s",(t1+1),(t2+1));
	int len=strlen(t1+1);
	int l,r;
	for(l=1;l<=len;l++)
		if(t1[l]!=t2[l]) break;
	for(r=len;r>=1;r--)
		if(t1[r]!=t2[r]) break;
	if(l>r) return;
	string Str;
	for(int i=l;i<=r;i++) Str+=t1[i];
	for(int i=l;i<=r;i++) Str+=t2[i];
	if(mp[Str]==0) {ans[Id]=0;}
	else
	{
		Node tmp; tmp.id=Id;
		string L; L='a';
		for(int i=l-1;i>=1;i--) L+=t1[i];
		string R; R='a';
		for(int i=r+1;i<=len;i++) R+=t1[i];
		int ID=mp[Str];
		for(int i=0;i<a[ID].size();i++)
		{
			Node u=a[ID][i];
			if(Pre(a[ID][i].l,L)&&Pre(a[ID][i].r,R)) ans[Id]++;
		}
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cout<<"A\n";
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++) works();
	for(int i=1;i<=q;i++) workq(i);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
