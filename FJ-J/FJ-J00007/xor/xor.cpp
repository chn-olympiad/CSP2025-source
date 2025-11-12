/*
T3 ，小卡一下。不知道数据范围是何意味，自认为不需要限制ai大小
我们记录一个xor前缀和数组s,si表示a1^a2^...^ai。
从前向后扫一遍，记录一个类似lazy tag的东西（就是说暴力的想，由于我提前处理了前缀和。所以我要枚举区间的起点）
[l,r]的xorsum=[xorsum][1,l]xor[xorsum][1,r]
然后枚举到一个区间的时候，如果成功。那么直接向后记录即可（贪心的想，如果一个极大的区间答案是k如果其中有一个子区间xorsum是k那么我选取这个子区间一定更优）
然后这个其实是n^2的，我们从ai范围入手，实际上就是枚举r（钦定rq为上一个r），然后检查sr xor k是否在i in [rq,r] ,si里面，用桶记录不难维护，每遇到一个合法的r把桶清空即可 
自评难度：上位黄~下位绿 
思考用时：30min
代码用时： INF
9:32 过大样例
这道题还是挺思维的，早上状态不太好，这道题有助于我活动活动脑子 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int xors[N];
bool t[2000000];
int qr,ret;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	xors[1]=a[1];
	xors[0]=0;
	for(int i=2;i<=n;i++)
	{
		xors[i]=xors[i-1]^a[i];
	}
	t[0]=1;
	for(int i=1;i<=n;i++)
	{
		//cout<<(xors[i]^k)<<"\n";
		if(t[xors[i]^k])
		{
			ret++;
			for(int j=qr;j<=i;j++)
			{
				t[xors[j]]=0;
			}
			qr=i;
			t[xors[i]]=1;
		}
		else
		{
			t[xors[i]]=1;
		}
	}
	cout<<ret;
} 
