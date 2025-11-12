#include <bits/stdc++.h>
using namespace std;

int n, q, ans;
struct str{
	string a;
	string b;
}s[200005];
string s1,s2;
//定义定义jjj


bool same(int st, int en, string a, string b){
	int len = b.size();//首先获取长度
	if(en-st+1 != len) return 0;//如果两个都不一样长，那直接return 
	for(int i = 0; i < len;i++) {//ok现在从字符串b开始
		if(a[i+st] != b[i])return 0;//如果a的某一位和b的某一位不一样，之间诶return
	}
	return 1;//到这里代表都一样，return 1
}
//判断两个字符串，是否相等
//这里为了更加实用，在这里加上了两个下标
//其实是因为我自己把函数忘记了，只能写这个了jjjj
//然后涅，就是判断a字符串的st到en是否与b字符串相等

int check(int x11, int x21, string y11, string y21){
	int len = y11.size();//随便获取一个长度
	for(int i = 0; i < x11; i++) if(y11[i] != y21[i]) return -1;
	for(int i = x21+1; i < len; i++) if(y11[i] != y21[i]) return -1;//如果X Z 已经不满足了，那么直接返回-1表示两个指针存在问题
	
	for(int i = 0;i < n; i ++){//便利每一个谐音geng
		if( same(x11,x21,y11,s[i].a) &&  same(x11,x21,y21,s[i].b) ) return 1;//如果两个中间刚好相同返回1.表示可以
	}	
	
	return 0;//所有都便利了，还是没有直接返回0
}
//这个函数是判断谐音geng是否可以和下面双指针所示分割，作用为检查

int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;//jjj一开始先输入谐音的数量和询问的次数
	for(int i = 0; i < n ;i ++ ) {
		cin >> s[i].a >> s[i].b;//直接输入可以替换的谐音
	}
	while(q--) {//okok此处是对于每一次查询
		ans = 0;//清0 每次都是新的一个
		cin >> s1 >> s2;//输入目标字符串
		int len = s1.size()-1;
		int le;  int re;  le = 0;  re = len;
		//这里有一个不成型的双指针想法
		//因为反正到最后都是变成X+Y+Z
		//所以直接把两个指针变成两个加号
		for(le = 0;le <= re ;le ++){//循环左边的指针
			for(re = len; re >= le; re --){//循环右边的指针，慢慢收拢
				int ls = check(le, re, s1, s2);//检查当前的这个分割方式可不可以达到目标
				
				if (ls == -1 ) break;//如果X Z 不满足，直接break
				else if (ls == 1) {
					ans ++;
					cout << le << re<<endl;
					//如果中间的不满足，就不用管，这是满足中间的，直接让答案+1
				}
			}
		}
		cout << ans << endl;//输出答案
	}
	return 0;
}
//eee盲写代码n年之久发现最简单的测试数据过不了
//于是我要变成小黄鸭了jiaojiaojiao
//现在时间17：09
//现在时间17：35
//666检查半天，bug还是没有排除hhh
