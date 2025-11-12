#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,q,cnt;long long ans;
string sl[200005],sr[200005],tl[200005],tr[200005];
struct intt{
	int fail;char c;vector<int> final;int son[27];bool rson[27];
}a[5000010];
void build(string x,int _)
{
	int now=0;
	for(int i=0;i<x.size();i++)
	{
		if(!a[now].son[x[i]-'a'])a[++cnt].c=x[i],a[now].son[x[i]-'a']=cnt,a[now].rson[x[i]-'a']=1;
		now=a[now].son[x[i]-'a'];
	}
	a[now].final.push_back(_);
	return ;
}
void make_fail()
{
	queue<int>q;int x;
	for(int i=0;i<26;i++)if(a[0].rson[i])q.push(a[0].son[i]);
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(a[x].rson[i])q.push(a[x].son[i]),a[a[x].son[i]].fail=a[a[x].fail].son[i];
			else a[x].son[i]=a[a[x].fail].son[i];
		}
	}
}
vector<pair<int,int> > find(string str)
{
	int now=0;
	vector<pair<int,int> >s;
	for(int i=0;i<str.size();i++)
	{
		if(a[now].rson[str[i]-'a'])now=a[now].son[str[i]-'a'];
		else now=a[a[now].fail].son[str[i]-'a'];
		int tmp=now;
		while(tmp)
		{
			for(int j=0;j<a[tmp].final.size();j++)
			s.push_back(make_pair(i-sl[a[tmp].final[j]].size()+1,a[tmp].final[j]));
			tmp=a[tmp].fail;
		}
	}return s;
}
void slove(string x,string fn)
{
	vector<pair<int,int> >s=find(x);
	for(int i=0;i<s.size();i++)
	{
		int plc=s[i].first,p=s[i].second;string tmp=x;
		//cout<<sl[p]<<' '<<sr[p]<<endl;
		//printf(" %d %d %d\n",i,plc,p);cout<<sl[p]<<' '<<sr[p]<<endl;
		for(int j=plc;j<=plc+sl[p].size()-1;j++)tmp[j]=sr[p][j-plc];
		//cout<<tmp<<endl;
		if(tmp==fn)ans++;
	}return ;
}char x[5000001],y[5000001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)scanf("%s %s",&x,&y),sl[i]=x,sr[i]=y,build(sl[i],i);
	make_fail();
	for(int i=1;i<=q;i++)scanf("%s %s",&x,&y),tl[i]=x,tr[i]=y;
	for(int i=1;i<=q;i++)ans=0,slove(tl[i],tr[i]),printf("%d\n",ans);
	//vector<pair<int,int> >s=find("uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp");cout<<s.size();
	return 0;
}
//说好不考字符串的!!!
//AC好难打… 
//TLE!!!都怪vector!!! 
//想改…但没时间了
//已经燃尽了么 
//窝不想AFO QAQ 
