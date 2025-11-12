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
constexpr int N=507;
using namespace std;
int n,m;
string st;
bool s[N];
int p[N],c[N];
inline bool check()
{
	int x=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(c[p[i]]>=x)
		{
			x++;
			continue;
		}
		if(s[i]) x++;
		else ans++;
	}
	return (ans>=m);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++) s[i]=st[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do
	{
		if(check()) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	cout.flush();
	return 0;
}
