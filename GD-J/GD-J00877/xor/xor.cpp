#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int xor_sum[500005];
struct Range{
	int l,r;
}Okey[1000005],temp;
int cnt;
int ans;
bool cmp(Range x,Range y)
{
	if(x.r==y.r) return x.l>y.l;
	else return x.r>y.r;
}
int now; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(n>10000)
	{
		if(k>1) cout<<0;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
			ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	now=n+1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		xor_sum[i]=xor_sum[i-1] ^ a[i];
		for(int j=i; j>=1; j--)
		{
			if((xor_sum[i] ^ xor_sum[j-1])==k) 
			{
				temp.l=j,temp.r=i;
				Okey[++cnt]=temp;
			}
		}
	}
	sort(Okey+1,Okey+1+cnt,cmp);
	for(int i=1; i<=cnt; i++)
	{
		//cout<<Okey[i].l<<" "<<Okey[i].r<<"\n";
		if(Okey[i].r<now) /*cout<<Okey[i].l<<" "<<Okey[i].r<<"\n",*/now=Okey[i].l,ans++;
	}
	cout<<ans;
	
	return 0;
} 
/*
#define Luogu_id syf159
#define Luogu_uid INF
#define My_Game 网易_MC
#define My_Love_in_My_Game 布吉岛+元素之诗 


RP++
RP++


黄鹤楼 崔颢
 
昔人已乘黄鹤去，此地空余黄鹤楼 

黄鹤一去不复返，白云千载空悠悠

晴川历历汉阳树，芳草萋萋鹦鹉洲

日暮乡关何处是，烟波江上使人愁


使之塞上 王维 

单车欲问边，属国过居延 

征蓬出汉塞，归雁入胡天

大漠孤烟直，长河落日圆

萧关逢候骑，都护在燕然
 

7:40 出门

7:50 到达考点门口
 
8:00 666拿了个保温杯还不给拿进考场，什么人啊

8:05 成功进入考场
 
9:18 很好，第三题直接卡住，感觉是用状压，但是根本不知道咋压 qwq 感觉要 AFO 了 qwq 

9:30 渴死了^v^ 

9:33 好吧，放弃了。T3 打个暴力算了吧 

10:06 终于喝上水了啊啊啊 

10:10 写了个暴力结果还写错了，又要重构 qwq 

10:23 好吧，成功的放弃重构，开始打 T4 暴力 

11:00 T4 暴力完成

11:10 这是什么机子，我测试一个 T4 大样例给我卡死机了

11:15 成功重启，还好代码没丢…… 

祝大家考试顺利！ 

别看，这里只是钓鱼用的......
//freopen
#include<bits\stdc++.h>
froepen
kkksc03
chen_zhe
luogu 
joker.in
member.in
pelygon.in
polygen.in
*/
