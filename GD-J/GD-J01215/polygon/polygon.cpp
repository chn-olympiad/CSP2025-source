//HD 
//先排序 
//设 f_x 为使 s=x 的方案数(n>=2)
//g_x 为使 a_i=x 的方案数 
//y为x>V的方案数 
//对于 ai:
//ans+=y+sum{f[p]}(p:ai+1->V)
//y*=2
//y+=sum{f[p]+g[p]}(p:V-ai+1->V)
//f[ai+p]+=f[ai]+g[ai](ai+p<=V)
//g[ai]++ 
//O(nV)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005,mod=998244353;
ll a[N],n;
ll g[N],f[N],ans,y;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		ans=(ans+y)%mod;
		for(int j=a[i]+1;j<=5000;j++) ans=(ans+f[j])%mod;
		y=(y*2)%mod;
		for(int j=5000-a[i]+1;j<=5000;j++) y=(y+f[j]+g[j])%mod;
		for(int j=5000;j>=a[i]+1;j--) f[j]=(f[j]+f[j-a[i]]+g[j-a[i]])%mod;
		g[a[i]]++;
	}
	cout<<ans;
}
//今年的题好水
//全都一眼秒了
//10:00 就写完了 罚坐 2h
//让我想想整什么活才能上迷惑行为大赏 
//下午 S rp++
//雨下整夜 我的爱溢出就像雨水
//院子落叶 跟我的思念厚厚一叠
//几句是非 怎能让我的热情冷却
//你出现在我诗的每一页
//雨下整夜 我的爱溢出就像雨水
//窗台蝴蝶 像诗里纷飞的美丽章节
//我继续写 把永远爱你写进诗的结尾
//你是我唯一想要的了解

//这里原本有一个  的 
//Luogu uid:934048 Genshin uid:243180373 Lv.56 (萌新求带)
