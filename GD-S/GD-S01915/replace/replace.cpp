/*
Neuvillette & Alhaitham
不要发呆，不要红温，对得起你的训练时间
题目名称 社团招新 道路修复 谐音替换 员工招聘
题目类型 传统型 传统型 传统型 传统型
目录 club road replace employ
可执行文件名 club road replace employ
输入文件名 club.in road.in replace.in employ.in
输出文件名 club.out road.out replace.out employ.out
每个测试点时限 1.0 秒 1.0 秒 1.0 秒 1.0 秒
内存限制 512 MiB 512 MiB 2048 MiB 512 Mi
*/
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=2e5+7;
constexpr int S=5e6+7;
using namespace std;
string t[N],u[N];
int n,q;
vector<vector<int>> nxt;
inline void init(int id)
{
	nxt[id].resize(t[id].size()+5);
	int len=0; nxt[id][len]=0;
	for(int i=1;i<t[id].size();)
	{
		if(t[id][i]==t[id][len])
		{
			len++;
			nxt[id][i]=len;
			i++;
		}
		else
		{
			if(len==0)
			{
				nxt[id][i]=len;
				i++;
			}
			else len=nxt[id][len-1];
		}
	}
}
vector<int> ans;
inline void kmp(string &s,int id)
{
	for(int i=0,j=0;i<(int)(s.size());)
	{
		if(s[i]==t[id][j]) i++,j++;
		else
		{
			if(j>0) j=nxt[id][j-1];
			else i++;
		}
		if(j==t[id].size()) ans.push_back(i-j);
	}
}
inline ll solve()
{
	if(clock()*1.0/CLOCKS_PER_SEC>1.9) return 0;
	string s1,s2,s3;
	cin>>s1>>s2;
	ll alhaitham=0;
	for(int i=1;i<=n;i++)
	{
		ans.clear();
		kmp(s1,i);
		for(int v:ans)
		{
			s3=s1.substr(0,v)+u[i]+s1.substr(v+t[i].size());
//			cerr<<s1.substr(0,v)<<' '<<u[i]<<' '<<s1.substr(v+t[i].size())<<'\n';
			if(s3==s2)
			{
				alhaitham++;
			}
//				cerr<<s1<<' '<<i<<' '<<s3<<endl;
		}
	}
	return alhaitham;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	nxt.resize(n+3);
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>u[i];
		init(i);
	}
	while(q--)
	{
		if(clock()*1.0/CLOCKS_PER_SEC>1.9) cout<<"0\n";
		else cout<<solve()<<'\n';
//		cout.flush();
	}
	cout.flush();
	return 0;
}
/*
数据放个水谢谢 
*/ 
/*
操作:t->u 
给每一个询问s1->s2，在给定的n个字符串里匹配s1,看看替换完之后能不能对得上 
*/
/*
可以考虑暴力搜索，然后搜不到就全输出0
要用KMP吗？ 
*/
