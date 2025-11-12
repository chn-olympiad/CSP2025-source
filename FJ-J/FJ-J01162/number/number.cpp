#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
string n;
int a[1000005],l2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	int l = n.length();
	for(int i = 0;i < l; i++){
		if(n[i] >= '0' && n[i] <= '9'){
			l2++;
			a[l2] = n[i]-'0';
		}
	}
	sort(a+1,a+l2+1);
	for (int i = l2; i >= 1; i--){
		cout << a[i];
	}
	return 0;
}
//你好，我认识你很高兴
//我叫伯特，别问我你贵姓
//我今年今天是二十岁了
//我惊持二的时候我还说对你对了
//我的专业是环境氪学
//如果我学霜上加学 
//我从来没有穿过裤子
//我没有朋友 我只有兔子
//我我和你一心连心同同住地球村
//我我和你一心连心同同住地球村村
//我我和你一心连心同同住地球村
//我我和你一心连心同同住地球村 
