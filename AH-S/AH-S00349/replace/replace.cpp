#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],d1[200005],d2[200005];
int trie[5000005][26],cnt=1;
vector<int> e[5000005];
void update(string s,int x)
{
	int p=1;
	for(int i=0;i<(int)s.size();i++)
	{
		if(!trie[p][s[i]-'a']) trie[p][s[i]-'a']=++cnt;
		p=trie[p][s[i]-'a'];
	}
	e[p].push_back(x);
}
int query(string dif1,string dif2,string t1,string t2)
{
	int p=1;
	for(int i=0;i<(int)dif1.size();i++)
	{
		if(!trie[p][dif1[i]-'a']) return 0;
		p=trie[p][dif1[i]-'a'];
	}
	int ans=0;
	for(int i=0;i<(int)e[p].size();i++)
	{
		int x=e[p][i];
		if(dif2!=d2[x]) continue;
		if((int)t1.find(s1[x])!=-1 && (int)t2.find(s2[x])!=-1) ans++;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]) {d1[i]=d2[i]="";continue;}
		int l=s1[i].size();
		int p1=0,p2=l-1;
		for(int j=0;j<l;j++)
			if(s1[i][j]!=s2[i][j]){p1=j;break;}
		for(int j=l-1;j>=0;j--)
			if(s1[i][j]!=s2[i][j]){p2=j;break;}
		for(int j=p1;j<=p2;j++)
			d1[i]+=s1[i][j],d2[i]+=s2[i][j];
		update(d1[i],i);
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<'\n';continue;}
		string dif1="",dif2="";
		int l=t1.size();
		int p1=0,p2=l-1;
		for(int i=0;i<l;i++)
			if(t1[i]!=t2[i]){p1=i;break;}
		for(int i=l-1;i>=0;i--)
			if(t1[i]!=t2[i]){p2=i;break;}
		for(int i=p1;i<=p2;i++)
			dif1+=t1[i],dif2+=t2[i];
		cout<<query(dif1,dif2,t1,t2)<<'\n';
	}
	cout<<endl;
	return 0;
}
