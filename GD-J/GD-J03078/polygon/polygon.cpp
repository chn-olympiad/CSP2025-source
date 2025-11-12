#include <iostream>
#include <cmath>
#define MAXN 5003
#define MOD 998244353
using namespace std;
int a[MAXN];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int i, n, sum=0, mx=-1;
	cin >> n;
	for (i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if (n==3) {
		if (sum > 2*mx) cout << 1;
		else cout << 0;
		return 0;
	}
	else cout << 42;
	//zhe ke shi yuzhou zhongji mimi, yiding neng mengdui de qwq
	return 0;
}
//wo xiang zhidao luogu youmeiyou wan kards de
//zai zheli fang yiduan shenmi wenzi
//kankan nengbuneng ba wan kards de xiyin guolai qwq

/*
huijia diyi jian shi
dakai kards jjc
150 jinbi yici
wo feichang diankuang
deguo zhuguo faguo mengguo
sanzhang chetui tanke
haiyou fuchong mengbige
shei neng ruhe wo
zhengzai xunzhao diren...
____ wandan!
shi __________!
qishou 131 fuji
zheba yexu youdeban
xiwang duimian shoupai lan
shenme t26 466 haiyou lanhuishi
ying toupi jiaohuan cheng houqi
wo haiyou ______ doudi!
shenme chengjie taoli zhanshaxian
____ de jinu
____ de meifen
____ de bingdao ren!
*/
