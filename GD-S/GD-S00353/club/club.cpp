#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct yee{
	int k1,k2,k3;
}a[N];
bool cmp(yee x,yee y)
{
	if(x.k1!=y.k1) return x.k1>y.k1;
	else if(x.k2!=y.k2) return x.k2>y.k2;
	else return x.k3>y.k3;
}
int ca(int i,int p)
{
	return (p==1?a[i].k1:(p==2?a[i].k2:a[i].k3));
}
int t,n;
int f[N][4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int k=n/2,f1=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].k1>>a[i].k2>>a[i].k3;
			if(a[i].k2!=0||a[i].k3!=0) f1=0;
		}
		if(n==2)
		{
			int maxn=0;
			for(int i=1;i<=3;i++)
				maxn=max(maxn,ca(1,i)+max(ca(2,(i+1)%3),ca(2,(i+2)%3)));
			cout<<maxn<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if(f1)
		{
			int ans=0;
			for(int i=1;i<=k;i++) 
				ans+=a[i].k1;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j>=1;j--)
			{
				if(j>k)
					for(int p=1;p<=3;p++)
						f[j][p]=max(f[j][p],max(f[j-1][(p+1)%3],f[j-1][(p+2)%3])+ca(i,p));//cout<<ca(i,p)<<" "<<f[j][p]<<"^^^\n";
				else 
					for(int p=1;p<=3;p++)
						f[j][p]=max(f[j][p],max(f[j-1][p],max(f[j-1][(p+1)%3],f[j-1][(p+2)%3]))+ca(i,p));//cout<<ca(i,p)<<" "<<f[j][p]<<"%%%\n";
			}
				
		}
//		for(int i=1;i<=n;i++)
//			cout<<f[i][1]<<" "<<f[i][2]<<" "<<f[i][3]<<"\n";
		cout<<max(f[n][1],max(f[n][2],f[n][3]))<<"\n";
		memset(f,0,sizeof f);
	}
	return 0;
} 
/*
这风铃跟心动很接近
这封信还在怀念旅行
路过的爱情都太年轻
你是我想要 再回去的风景
这风景被瓶装成秘密
这雏菊美得想诗句
而我在风中等你 的消息
等月光落雪地 等枫红染上去等相遇
我重温午后的阳光 将吉他斜背在肩上
像多年前一样 我们轻轻的唱
去任何地方
我看着你的脸 轻刷着和弦
情人节卡片 手写的永远
还记得广场公园 一起表演
校园旁糖果店 记忆里在微甜
我看着你的脸 轻刷着和弦
初恋是整遍 手写的从前
还记得那年秋天说了再见
当恋情已走远 我将你深埋在心里面


微风需要竹林 溪流需要蜻蜓
乡愁般的离开 需要片片浮萍
记得那年的雨季 回忆里特安静
哭过后的决定 是否还能进行
我傻傻等待 傻傻等春暖花开
等终等于等明等白等爱情回来
青春属于表白 阳光属于窗台
而我想我属于一个拥有你的未来
纸上的彩虹 用素描画的钟
我还在修改回忆之中你的笑容
该怎么去形容 我思念异常的痛
夜空霓虹 都是我不要的繁荣
或许去看看沙滩 或许去看看星空
或许去到一个可以想心事的地方
情绪在咖啡馆 被调成一篇文章
彻底爱上你如诗一般的泪光 
*/
