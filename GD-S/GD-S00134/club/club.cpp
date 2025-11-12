#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int x;
const int maxn=100001;
long long n,a[maxn][4],h1[maxn],h2[maxn],h3[maxn],k1=0,k2=0,k3=0,sum=0;
struct club1
{
	int sum1,k;
};
bool cmp(club1 x,club1 y)
{
	return x.sum1>y.sum1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>x;
	while(x--)
	{
		cin>>n;
		k1=k2=k3=sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))) h1[++k1]=i,sum+=a[i][1];
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))) h2[++k2]=i,sum+=a[i][2];
			else h3[++k3]=i,sum+=a[i][3];
		}
		if(k1>n/2)
		{
			long long ans2[maxn],del=k1-n/2;
			bool flag[maxn];
			memset(flag,0,sizeof(flag));
			club1 t[maxn];
			for(int i=1;i<=k1;i++)
			{
				t[i].k=h1[i];
				t[i].sum1=max(sum-a[t[i].k][1]+a[t[i].k][2],sum-a[t[i].k][1]+a[t[i].k][3]);
				if(t[i].sum1==sum-a[t[i].k][1]+a[t[i].k][2]) ans2[t[i].k]=2;
				else ans2[t[i].k]=3;
			}
			sort(t+1,t+k1+1,cmp);
			for(int i=1;i<=k1;i++)
			{
				if(del==0) break;
				if(ans2[t[i].k]==2&&k2<n/2&&!flag[t[i].k]) k2++,sum=sum-a[t[i].k][1]+a[t[i].k][2],flag[t[i].k]=1,del--;
				else if(ans2[t[i].k]==3&&k3<n/2&&!flag[t[i].k]) k3++,sum=sum-a[t[i].k][1]+a[t[i].k][3],flag[t[i].k]=1,del--;
			}
		}
		if(k2>n/2)
		{
			long long ans2[maxn],del=k2-n/2;
			bool flag[maxn];
			memset(flag,0,sizeof(flag));
			club1 t[maxn];
			for(int i=1;i<=k2;i++)
			{
				t[i].k=h2[i];
				t[i].sum1=max(sum-a[t[i].k][2]+a[t[i].k][1],sum-a[t[i].k][2]+a[t[i].k][3]);
				if(t[i].sum1==sum-a[t[i].k][2]+a[t[i].k][3]) ans2[t[i].k]=3;
				else ans2[t[i].k]=1;
			}
			sort(t+1,t+k2+1,cmp);
			for(int i=1;i<=k2;i++)
			{
				if(del==0) break;
				if(ans2[t[i].k]==3&&k3<n/2&&!flag[t[i].k]) k3++,sum=sum-a[t[i].k][2]+a[t[i].k][3],flag[t[i].k]=1,del--;
				else if(ans2[t[i].k]==1&&k1<n/2&&!flag[t[i].k]) k1++,sum=sum-a[t[i].k][2]+a[t[i].k][1],flag[t[i].k]=1,del--;
			}
		}
		if(k3>n/2)
		{
			long long ans2[maxn],del=k3-n/2;
			bool flag[maxn];
			memset(flag,0,sizeof(flag));
			club1 t[maxn];
			for(int i=1;i<=k3;i++)
			{
				t[i].k=h3[i];
				t[i].sum1=max(sum-a[t[i].k][3]+a[t[i].k][2],sum-a[t[i].k][3]+a[t[i].k][1]);
				if(t[i].sum1==sum-a[t[i].k][3]+a[t[i].k][2]) ans2[t[i].k]=2;
				else ans2[t[i].k]=1;
			}
			sort(t+1,t+k3+1,cmp);
			for(int i=1;i<=k3;i++)
			{
				if(del==0) break;
				if(ans2[t[i].k]==2&&k2<n/2&&!flag[t[i].k]) k2++,sum=sum-a[t[i].k][3]+a[t[i].k][2],flag[t[i].k]=1,del--;
				else if(ans2[t[i].k]==1&&k1<n/2&&!flag[t[i].k]) k1++,sum=sum-a[t[i].k][3]+a[t[i].k][1],flag[t[i].k]=1,del--;
			}
		}
		cout<<sum<<endl;
	}
}
//哇，代码正好100行，不过我还要写一点注释再说
//这个考场的checker居然还要自己输入题目名称，难怪跟去年显示的不一样=O
//第一题不知道能不能过，大样例都过了但是我还是不知道做法是不是错的=(
//听说高中有分就能进NOIP，如果我第一题炸了的话我就完蛋了qaq，别的题都没怎么写骗分
//现在是17:33分，我第四题的骗分还没开始写
//如果今年第一题也是橙题我就破大防，我可是写了2个多小时啊！不过好像也挺正常的，对于我这个总不写题蒟蒻来说（
//汉密尔顿音乐剧实在是太好看了！我昨天和今天硬拉着hwh看了1半=)
//说到hwh...马上就是他的生日了=O
//前两年我都在代码里写小作文，但今年我没想好怎么写，所以我先去骗分力，现在是17点37分=)
//第一题的大样例看起来值得信赖啊...千万别背刺我球球了QAQ
//我去还好检查了一遍，改完之后样例没过吓死我了，现在是18点13分
//没事变量名写错了，小问题qwq 
