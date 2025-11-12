#include <bits/stdc++.h>
#define O 200005
using namespace std;
struct rep
{
	string s1,s2;
}	lst[O];
int n,q,ans = 0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i = 1;i <= n;++i)
		cin >> lst[i].s1 >> lst[i].s2;
	for(int i = 1;i <= q;++i)	//q
	{
		ans = 0;
		string s1,s2,s3,s4;

		cin >> s1 >> s2;
		for(int k = 1;k <= n;++k)	//枚举替换规则,n
		{
			int S = s1.size() - lst[k].s1.size();
			for(int q = 0;q <= S;++q)	//
			{
				string ext = s1.substr(q,lst[k].s1.size()),Z;
				if(ext == lst[k].s1)	//可以替换,将前面的截取出来 
				{
					if(q + lst[k].s1.size() > s1.size())
						Z = "";
					else
						Z = s1.substr(q + lst[k].s1.size());
					s4 = s3 + lst[k].s2 + Z;
					if(s4 == s2)
						++ans;
				}
				s3 += s1[q];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
不难看出,题目似乎只允许我们替换一次子串
那么我们尝试枚举每一字符串替换对
查看它替换后是否与新字符串相等

O(nkq),能拿10分左右就不错了 
*/ 
