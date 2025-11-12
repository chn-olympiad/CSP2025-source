#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
#define int long long
using namespace std;
namespace Fast{
	inline int fr(){
		int x = 0,f = 1;
		char c = getchar();
		while (c < '0' || c > '9'){
			if (c == '-'){
				f = -1;
			}
			c = getchar();
		}
		while ('0' <= c && c <= '9'){
			x = (x << 1) + (x << 3) + (c ^ 48);
			c = getchar();
		}
		return x * f;
	}
	inline void fw(int x){
		if (x == 0){
			putchar('0');
			return ;
		}
		if (x < 0){
			x = -x;
			putchar('-');
		}
		stack <char> stk;
		while (x){
			stk.push(x % 10 + '0');
			x /= 10;
		}
		while (!stk.empty()){
			putchar(stk.top());
			stk.pop();
		}
	}
	inline void DEBUG(){
		cout<<"CSP-JS rp++; qwq\n";
	}
}

using namespace Fast;
struct P{
	int num,id;
}s[105];

bool cmp(P a,P b){
	return a.num > b.num;
}

signed main(){
	//我们考场排座顺序怎么跟题目里不一样 
	//看来小 R 不在我们考场, 不能去面积了 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n = fr(),m = fr();
	for (int i = 1;i <= n * m;i++){
		s[i].num = fr();
		s[i].id = i;
	}
	sort(s + 1,s + n * m + 1,cmp);
	int nowh = 1,nowl = 1,optx = 1;
	for (int i = 1;i <= n * m;i++){
		//cout<<i<<" ("<<nowh<<','<<nowl<<")\n";
		if (s[i].id == 1){
			fw(nowl),putchar(' '),fw(nowh);
			break;
		}
		if (nowh == n && nowl % 2 == 1){
			optx = -1;
			nowl++;
		}
		else if (nowh == 1 && nowl % 2 == 0){
			optx = 1;
			nowl++;
		}
		else{
			nowh += optx;
		}
	}
	return 0;
}
