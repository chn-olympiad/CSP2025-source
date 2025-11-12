#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=1e6+5;
int n;
char s[N];
vector<int>num;

bool cmp(int x,int y)
{
	return x>y;
 } 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>(s+1);
	n=strlen(s+1);
	
	_rep(i,1,n)
	{
		if(s[i]>='0'&&s[i]<='9')
			num.emplace_back((int)(s[i]-'0')); 
	}
	
	sort(num.begin(),num.end(),cmp);
	
	for(int x:num) cout<<x;
	cout<<"\n";
	return 0;
} 
/*
8:27 解压，Ruo 看成 Rw，鉴定为老师黑板字太拉了

前三题。T1 秒，T2 什么极小数据范围，T3 直接贪，顺序考虑，代码写丑了调的有点久，后来就重构。

9:04 前三题大样例全过，感觉 T3 大样例好水，怀疑自己做法有问题，想打拍。头脑风暴 20 min，貌似做法的正确性可以证明，自己感性证明就不打拍了。

T4 直接 dp，先打了个很显然的 O(nsum) 做法，能拿 80 分，真高。

9:50 大样例全过，因为没有极限数据。想怎么优化，看起来好典但我不会，想用 DS 来搞，不咋会修改。

9:56 启动！是虚拟机，刚学会的。

10:15 终于搞完了，自己测数据的方法太繁琐了。

在想会儿 T4 的 dp 优化，ok，其实都不会几个 dp 优化，不会。

10:34 启动！是蜘蛛纸牌。爽玩，8 min 直接二级了。

后面摆烂。  
*/ 
