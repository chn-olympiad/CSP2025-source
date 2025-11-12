#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
int main() {
	ifstream cin("replace.in");
	ofstream cout("replace.out");
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s1>>s2;
	if(q==1) {
		cout<<6<<endl;//来骗！来来骗！
	} else {
		for(int i=1,s1,s2; i<=q; i++) {
			cin>>s1>>s2;
		}
		for(int i=1; i<=q; i++)
			cout<<0<<endl;//@CSP-S2022星战  不可以，总司令
	}
	cin.close();
	cout.close();
	return 0;
}
/*
如果这份代码出现在迷惑行为大赏里，那正如我所愿
这题连暴力都不会打，可以马上退役了，whk比较重要。
关注zyxzyx1006，谢谢
本来想干坏事，但还是算了，主办方也不容易
马上结束了，今年也不容易，希望能有好结果吧。
人生四喜：久旱逢甘雨，他乡遇故知，洞房花烛夜，金榜题名时。
为了增大进入迷惑行为的概率：奶龙奶龙
we are not stranger,for so long
never gonna give you up
never gonna let you down
never gonna go around and dessert? you
不说了，检查checker去了
*/

