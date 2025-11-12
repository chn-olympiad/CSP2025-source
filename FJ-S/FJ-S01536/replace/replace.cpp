/*
1.开freopen
2.for循环
3.倒序遍历i--
4.开ll
5.数组溢出
6.初始化
7.删debug语句
8.n*m数组遍历
//*/
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<a.size();j++)
				if(s[i][0]==a.substr(j,s[i][0].size())
				 &&s[i][1]==b.substr(j,s[i][1].size())
				 &&a.substr(0,j)==b.substr(0,j)
				 &&a.substr(j+s[i][0].size())==b.substr(j+s[i][1].size()))
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}

