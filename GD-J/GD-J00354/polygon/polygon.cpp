#include<cstdio>
#include<cstdlib>
typedef long long LL;
const int N=25;

signed a[N], e[N]; int n;
signed int MAX(signed int x, signed int y) {return x>y? x:y; }

bool check(int len) {
	//听题目的，Sum(所有小木棍的长度) > Max(所有小木棍的长度) 
	signed maxa=-123456789, sum=0;
	for(int i=0;i<len;++i) maxa=MAX(maxa, e[i]), sum+=e[i];//遍历集合每个元素 
	return sum>maxa+maxa;//some+some比some*2或2*some效率高 
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%i",&n);
	if(n>N) return 1;//对不起，大于25的我无法处理
	int cnt=0;//方案总数 
	for(int i=0;i<n;++i) scanf("%i",&a[i]);
	for(int stt=0; stt<(1<<n); ++stt) {//共有(2^n)种状态 
		int len=0;//集合的元素
		for(int i=0;i<n;++i) if(stt&(1<<i)) e[len++]=a[i];//找出所有选的木棒 
		if(len<3) continue;//对不起，木棒不足3根 
		if(check(len)) ++cnt;//我不用mod 998244353，因为最多才33554432种状态 
	} 
	printf("%i",cnt);
	return 0;
} 
