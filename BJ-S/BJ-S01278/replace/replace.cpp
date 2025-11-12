#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
#define cin lyc
#define cout lmy
//cin loves cout!
ifstream cin("replace.in");
ofstream cout("replace.out");
unordered_map<string,pair<vector<int>,vector<int>>> group;
string calc(string& s,string& t)
{
	int x=0;
	while(s[x]==t[x])	x++;
	int y=s.size()-1;
	while(s[y]==t[y])	y--;
	return s.substr(x,y-x+1)+t.substr(x,y-x+1);
}
vector<string> str;
int nn,son[5000005][29],sum[5000005];
string s1[200005],s2[200005];
string t1[200005],t2[200005];
vector<pair<int,pair<int,string>>> tmp;
int n,q,ans[200005];
void clear()
{
	for(int i=0;i<=nn;i++)	sum[i]=0;
	for(int i=0;i<=nn;i++)
		for(int j=0;j<27;j++)
			son[i][j]=0;
	nn=1;
}
void insert(string s,int mode=1)
{
	int u=1;
	for(char ch:s)
	{
		if(!son[u][ch-'a'])	son[u][ch-'a']=++nn;
		u=son[u][ch-'a'];
	}
	sum[u]+=mode;
//	cout<<"sum["<<u<<"]+="<<mode<<"="<<sum[u]<<endl;
}
long long ask(string s)
{
	int u=1;
	long long anss=sum[u];
//	cout<<"+="<<anss<<" at O/\n";
	for(char ch:s)
	{
		if(!son[u][ch-'a'])	return anss;
		u=son[u][ch-'a'];
//		cout<<"+="<<sum[u]<<" at "<<u<<ch<<endl;
		anss+=sum[u];
	}
	return anss;
}
pair<string,string> split(string& s,string& t)
{
	int x=0;
	while(s[x]==t[x])	x++;
	string ttmp;
	int y=s.size()-1;
	while(s[y]==t[y])	ttmp+=s[y],y--;
	return make_pair(s.substr(0,x),ttmp);
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]!=s2[i])	group[calc(s1[i],s2[i])].first.push_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size())	continue;
		string tot=calc(t1[i],t2[i]);
//		cout<<t1[i]<<" "<<t2[i]<<" is variety "<<tot<<endl;
		if(!group.count(tot))	continue;
		group[tot].second.push_back(i);
	}
	for(auto iter:group)
	{
//		cout<<"group: variety="<<iter.first<<endl;
		vector<int>& ss=iter.second.first;
		vector<int>& ts=iter.second.second;
		str.clear();
		clear();
		tmp.clear();
		for(int x:ts)	str.push_back(split(t1[x],t2[x]).first);
		sort(str.begin(),str.end());
		for(int x:ts)
		{
			auto halves=split(t1[x],t2[x]);
			tmp.emplace_back(lower_bound(str.begin(),str.end(),halves.first)-str.begin(),make_pair(x,halves.second));
//			cout<<"#"<<lower_bound(str.begin(),str.end(),halves.first)-str.begin()<<": "<<halves.first<<","<<halves.second<<endl;
		}
		for(int x:ss)
		{
			auto halves=split(s1[x],s2[x]);
//			cout<<halves.first<<","<<halves.second<<endl;
			int l=lower_bound(str.begin(),str.end(),halves.first)-str.begin();
			int r=upper_bound(str.begin(),str.end(),halves.first+"{")-str.begin();
			tmp.emplace_back(l,make_pair(0,halves.second));
			tmp.emplace_back(r,make_pair(-1,halves.second));
//			cout<<"["<<l<<","<<r<<")+="<<halves.second<<endl;
		}
		sort(tmp.begin(),tmp.end());
		for(auto it:tmp)
			if(it.second.first<=0)	/*cout<<"ins: "<<it.second.second<<"+="<<it.second.first*2+1<<endl,*/insert(it.second.second,it.second.first*2+1);
			else	/*cout<<"ans["<<it.second.first<<"]+=ask("<<it.second.second<<")"<<endl,*/ans[it.second.first]=ask(it.second.second);
	}
	for(int i=1;i<=q;i++)	cout<<ans[i]<<"\n";
}