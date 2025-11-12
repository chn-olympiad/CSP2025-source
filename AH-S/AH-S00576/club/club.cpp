#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	char c=getchar();int f=1;
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-f,c=getchar();
	x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
const int N=2e5+5;
int T,n,a[N],b[N],c[N],used[N],d[N],deta[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in(T);
	while(T--){
		in(n);
		long long ans=0;
		int cnt[4]={0},cc=0;
		for(int i=1;i<=n;i++){
			in(a[i]);in(b[i]);in(c[i]);
			ans+=max(a[i],max(b[i],c[i]));
			int mxx=max(a[i],max(b[i],c[i])),mnn=min(a[i],min(b[i],c[i]));
			deta[i]=mxx-(a[i]+b[i]+c[i]-mxx-mnn);
			if(a[i]>=b[i]&&a[i]>=c[i])cnt[used[i]=1]++;
			else if(b[i]>=a[i]&&b[i]>=c[i])cnt[used[i]=2]++;
			else if(c[i]>=a[i]&&c[i]>=b[i])cnt[used[i]=3]++;
		}
		if(max(cnt[3],max(cnt[1],cnt[2]))<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		else{
			int id=1;
			for(int i=1;i<=3;i++){
				if(cnt[i]>n/2){
					id=i;break;
				}
			}
			int ned=cnt[id]-n/2;
			for(int i=1;i<=n;i++){
				if(used[i]==id)d[++cc]=deta[i];
			}
			sort(d+1,d+cc+1);
			for(int i=1;i<=ned;i++)ans-=d[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
《夏夜空》
花火绽放 在孤独梦中
点燃瞳孔 延伸了苍穹
想要去触动 在你眼中的夏夜空

不随波逐流的人注定要孤独
徘徊在都市的阴暗面中
连最后的呼唤都淡去的空中
仰望着愈加黯淡的天空
今天的意义不明该去向何处
对无法改变的保持麻木
就这样快褪去了原来的温度
将叛逆全部扼杀在迟暮
谁人仍会凝望着 儿时的夜空
因为平凡的日子 而露出笑容
花火绽放 在孤独梦中
点燃瞳孔 延伸了苍穹
想要去跟从 坠入这片夏夜空
最后一秒 因何而动容
无法逃离 成长的牢笼
闪烁的泪光 模糊了夏夜空

之所以能够离去而义无反顾
仅因我记得你已厌倦的梦
连最后的道别都稀薄的空中
用加倍的叛逆做出抗争
晨昏线再一次将这城市分割
而我只能在阴影中存活
今天的我将无理盲目追赶着
一遍一遍自问自答着什么
一直与你擦肩而过
远去的景色
将那日懦弱的我
一并丢弃了
星光弥散 在这宇宙中
哪片虚空 值得去停留
感谢这礼物 曾灿烂过的夏夜空
最后一秒 是遗憾的泪
孤身一人 并非残缺的美
你会在何处的夏夜里安睡

夜空从不会 因谁离开而改变
就算千万次晴朗后又是雨天
幸福悬挂在 每个平凡的夜晚
感谢它曾让生命灿烂
多日的阴雨之后 天青的蓝色
却将眼眶染红了 融化了青涩

花火绽放 在孤独梦中
点燃苍穹 润湿了瞳孔
想要去跟从 坠入这片夏夜空
最后一秒 请不要说话
道别之前 回忆起来吧
两个人一同 关于成长的梦

*/