#include<bits/stdc++.h>

using namespace std;

#define x1 maimaim41m41
#define x2 chunithmchu2thm
#define y1 ongeki0n93k1
#define y2 phigrosph9r

typedef long long ll;
int n;

const int N = 2e5+5;
// 完了我某些代码写习惯了
// 感觉我现在 cout 都要变成 print 了
// 然后啥都要写个 struct 或者 class
// 变量命名也开始变长且 hitoFutaMi（指大小写排布方式，不知道该怎么描述）化，
// 在 T2 代码里面尤为明显
// 然后运行也第一时间按下 F5 了，
// 可能是我在写给木软件写 gds 调试调多了
// 总之是代码更长了，OI 思路更没了，我也更被了
// 到时候期中化学别给我来个大爆炸就可以了

// 算了（liao）算了（liao），代码不能机选
// 写成这样直接交上去
// 就会发现机房的同学太强了非常之牛

// T3 写了个假做法（确信）
// 那就这样吧

// 看看 #define 行就会发现代码的神奇之处
// 总之这很可能是我最后一次打 csps
// 然后打完就直接去哪里不知道去打 chu2 算了

struct Member{
	int maxi; // 致敬传奇
	int inwhich; // 在哪个组里面有最大值
	int diff; // 对于第二个选项的差值
}memb[N];
struct IPlayMaimaidx{
	int val;
	int group;
}pl[5];
int cnt[5];
int diff[N];
void print(int x){
	cout<<x<<'\n';
	// 我有后遗症
}
void maisolve(){
	cin>>n;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>pl[j].val;
			pl[j].group = j;
		}
		sort(pl+1, pl+1+3, [&](IPlayMaimaidx x, IPlayMaimaidx y){
			return x.val > y.val;
		});
		memb[i].maxi = pl[1].val;
		memb[i].inwhich = pl[1].group;
		memb[i].diff = pl[1].val - pl[2].val;
		ans += memb[i].maxi;
		cnt[memb[i].inwhich] ++;
	}
//	cout<<ans<<'\n';
	for(int j=1;j<=3;j++){
//		print(cnt[j]);
		if(cnt[j] > n/2){
			int diffcnt = 0;
			for(int i=1;i<=n;i++){
				if(memb[i].inwhich == j){
					diff[++diffcnt] = memb[i].diff;
				}
			}
			sort(diff+1, diff+1+diffcnt, [&](int x, int y){return x<y;});
			for(int i=1;i<=cnt[j]-n/2;i++){
				ans -= diff[i];
			}
		}
	}
	cout<<ans<<'\n';
	
}
void duoceclear(){
	for(int i=1;i<=3;i++) cnt[i] = 0;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		maisolve();
		duoceclear();
	}
	return 0;
	
}
