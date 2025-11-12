#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
//第一题,考虑动态规划，不知道怎么写2/n的判断，死了 
//15:14;不妨考虑贪心吧，以人为单位建立数据结构，先把每个人的那三个数据按大到小排序，再按每个人的最大贡献排序，再按顺序分配部门并且用cnt统计每个部门的人数
//若有的超过了一半则分配给那个人的次大贡献部门，以此类推
//15:21;思路想完了，代码呢 <
//15:26;记得每组数据后归零 (a,now;clear
//15:47;这不对吧哥们pair的数据叫啥啊 
//15:50;为什么叫first和second 
//15:55;鬼故事：这是个dp题，贪心思路有问题。 
//16:00;尽力了尽力了， dp我也没思路啊，要不再加个特判算了？算了加都懒得加，祈祷吧各位 
//16:10;我觉得贪心正常讲没什么问题，待会想下特判 
//17:26;666T3写了个On^4的，也是个人物，回来想题，dp有机会吗宝贝
//17:29;开始重构，对于dp[i]，其含义为第i个人进1厂、2厂、3厂的最大值 
//17:44;退役。
//17:48;拼尽全力无法战胜，不过我是不是可以搞一份不考虑容量的 
struct per{
	pair<int,int>a1,a2,a3;
};
int t,n;
vector<per>a;
per makeup(per nn)
{
	if(nn.a3.second>nn.a2.second)swap(nn.a3,nn.a2);
	if(nn.a2.second>nn.a1.second)swap(nn.a1,nn.a2);
	if(nn.a3.second>nn.a2.second)swap(nn.a3,nn.a2);
	return nn;
}
bool cmp(per a,per b)
{
	return a.a1.second<b.a1.second;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	a.reserve(100005);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			per in;
			in.a1.first=0;in.a2.first=1;in.a3.first=2;
			cin>>in.a1.second>>in.a2.second>>in.a3.second;
			in=makeup(in); 
			a.push_back(in);
		}
		vector<int>now(3);//统各部门计人数 
		//15:35;到了这里，应该是实现了创建角色并且把三要素排好序了，接下来就应该贪心大法好了
		//15:36;突发奇想，没事了证伪了。。。
		sort(a.begin(),a.end(),cmp); 
		long long half=n/2,ans=0;
		for(int i=0;i<a.size();i++){
			if(now[a[i].a1.first+1]<=half)
			{
				ans+=a[i].a1.second;
				now[a[i].a1.first]++;
			}
			else
			{
				ans+=a[i].a2.second;
			}
		}
		cout<<ans<<endl;
		a.clear();
	}
	return 0;
}
