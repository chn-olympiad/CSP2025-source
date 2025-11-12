#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long n,a[5005],c[5005],m,ans,f,g;
bool b[5005],d[5005],e;
void pq(){
	long long maxx = -1,num=0;
	for (int i = 1; i <= m; i++){
		maxx = max(c[i],maxx);
		num += c[i];
//		cout << c[i] << " ";
	}
//	cout << endl;
	if(num > maxx*2){
		ans++;
		ans = ans%998244353; 
	}
}
void qp(int x){
	//全排不会打 ！！！ 
	//非常好的木棍问题，使我测试输出棍木 
	//哦原来测试只是输出endl啊我是艾斯比 
	//666自己摸索出来了 
	if(!b[x]){
		for (int i = x; i <= n-3+x; i++){
			if(!d[i] && i <= n && a[i] >= c[x-1]){
				b[x] = true;
				c[x] = a[i];
				d[i] = true;
				if(x == m){
					pq();
					if(f == ans){
						b[x] = false;
						d[i] = false;
						break;
					}
					f = ans;
				}
				else{
					qp(x+1);
				}
				b[x] = false;
				d[i] = false;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n-2; i++){
		if(!e){
			m=i+2;
			qp(1);
		}
		if(g == ans){
			break;
		}	
		g = ans;
	}
	cout << ans;
	return 0;
}
//rks++
//dr_geng_xin_zhang_shu++
//fang_fei_xiao_gao++ 
//bai_ri_zhan_ji++
//rs++
//exp--
//tousu++
//fans++
//arms -= 2
//诶考试结束还剩一个小时二十分钟
//写篇小作文
//时代的变迁——三角符文第三章游后感
//    Toby fox是一个游戏制作人。他做的游戏简单，但内部却含着许多道理。
//    在《三角符文》第三章中，有一个电视机。他的名字叫Tenna。它是一个
//苦命的电视机，曾经，很多人围在他的旁边，一起看电视，一起说笑。直到 
//某一天，新玩意的加入，Tenna渐渐无人在意。围在它身边的人越来越少，直
//至几乎没有。可有天，Susie来到了Kris家，看起了Tenna，Kris又脱离玩家 
//控制，开启了黑暗喷泉，赋予了Tenna生命。呼啸骑士告诉它，只要不惜一 
//切代价把主角留住，呼啸骑士就会让Tenna有人看。
//    到了主角团来到暗世界，Tenna也的确这样做了。它做了一个又一个的节 
//目，一个又一个枯燥乏味的节目，试图留下主角团。它坚持复古才是王道，却 
//不知道复古已成为人们不喜欢的东西。Tenna为了让主角团留下来，甚至压榨 
//员工。当它试图让天气留下来，它却不知道手机里的天气已经取代了电视里的 
//天气预报。最后，连MIKE都离它而去。Tenna做的一切事，就是想博主角团关注，
//想要自己有人看。可是，没人愿意看它，时代已经取代了它。所以，当Susie请 
//求能不能把它给其他人看时，Tenna无比的开心。可见，时代的变迁，已经取代 
//了老物件。
//    如今，时代不断在变化，新东西不断在退出，可旧物件却只能退出时代的
//舞台。作为人类，我们应当重视老文化的保存与传播，不让老文化渐渐消失。
//史 
//写完就要被chai
//(手臂被拆了)
//(装回去了)
//666二十分钟文章速成
//无聊死了 
//你说你不想在这里！
//我也不想在这里！
//但天黑的太快想走早就来不及！
//哦我 你！
//可惜关系变成没关系！
//问题是没问题！
//鱼食窝门急需！
//好吧改了一下代码 
