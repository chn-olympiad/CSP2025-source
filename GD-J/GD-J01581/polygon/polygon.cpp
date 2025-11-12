#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 998244353
using namespace std;
int n,sum,a[50];

int fast_pow(int x){
	int t=2,ans=1;
	while(x){
		if(x&1==1) ans=(ans*t)%MOD;
		t*=t;
		x>>=1;
	}
	return (ans)%MOD;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=fast_pow(n);i++){
		int t=i;
		int j=1;
		int num=0,maxn=0,sum1=0;
		while(t){
			if(t&1==1){
				num++;
				sum1=(sum1+a[j])%MOD;
				maxn=max(maxn,a[j]);
			}
			j++;
			t>>=1;
		}
		if(num>=3 && sum1>2*maxn) sum=(sum+1)%MOD;
	}
	cout<<(sum+MOD)%MOD;
	return 0;
	/*天空灰的像哭过
	离开你以后 并没有 很自由
	酸酸的空气 嗅出我们的距离
	一幕锥心的结局
	像呼吸般无法停息
	抽屉泛黄的日记
	榨干了回忆 这笑容 是夏季
	你我的过去 被顺时针地忘记
		缺氧过后的爱情
	粗心的眼泪是多余
	我知道你我都没有错
	只是忘了怎么退后
	信誓旦旦给了承诺
	却被时间划了空
	我知道我们都没有错
	只是放手会比较好过
	最美的爱情
	回忆里待续
	晴天 搁浅 爱你没差 花海 青花瓷 兰亭序 反方向的钟 夜的第七章 以父之名 白色风车 娘子 火车叨位去 圣诞星 爱的飞行日记 我落泪情绪零碎 枫 手写的从前 等你下课 不该 退后 轨迹 借口 说好的幸福呢 七里香 蒲公英的约定 龙卷风 告白气球 可爱女人 简单爱 半岛铁盒 爱在西元前 暗号 最长的电影 
	*/
}
