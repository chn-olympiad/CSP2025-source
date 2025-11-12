#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct s{string u,v;}a[114514*2];
string s1,s2,s3;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].u>>a[i].v;
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) {cout<<"0\n";continue;}
		for(int x=1;x<=n;x++)
		{
			int p=s1.find(a[x].u);
			if(p!=-1)
			{
				s3=s1;
				for(int idx=0;idx<a[x].u.length();idx++) s3[idx+p]=a[x].v[idx];
				if(s3==s2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//I love CCF
//rp++;
/*
	连狙红蛋 飞弹身后背
	总裁两队 像非法组队
	想撤离他不配
	乌鲁鲁~
	蚀金玫瑰 又夺舍了谁诶
	想要丢包 又不小心跳水诶
	护航无能的追
	你说你有点的狼狈 想鼠道混烟撤退
	燃烧瓶位置猜对 飞弹也紧紧跟随
	你像个贪吃小鬼 年轻人倒头就睡
	在桥上就拥有 全世界
*/ 
