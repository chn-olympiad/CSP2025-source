#include<bits/stdc++.h>
using namespace std;
#define int long long
int lst;
unordered_map<int,int> m;
int a[500010];
int n,ans,k;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
	for(int i=0;i<=n;i++)
	{
		if(m.count(a[i]^k) and m[a[i]^k]>=lst)
		{
			ans++;
			lst=i;
		}
		m[a[i]]=i;
	}
	cout<<ans;
}
/*
9:34
秒了前三题
发现不会第四题
前来写俳句

不闹了。

9:46
发现 D 可以推成背包。
想到三次方做法。

10:00
写出三次方做法。

10:10左右
想到正解。

10:25
打完正解。

不知道干什么。
我要上迷惑行为。

luogu TH_HaZel
*/
