#include<bits/stdc++.h>
using namespace std;
const int P=15;
string str;
int t[P];
bool fl;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++) {
		if(str[i]>='0'&&str[i]<='9') {
			t[str[i]-'0']++;
			if(str[i]!='0') fl=1;
		}
	}
	if(!fl) cout<<0;
	else {
		char c='9';
		for(int i=9;i>=0;i--) {
			for(int j=1;j<=t[i];j++) cout<<c;
			c--;
		}
	}
}
//北中啊！啊！中北！
//挑战不写 T1 拿下 1=
//算了第一次可能 AK J
//明年挑战 敬请期待
//期望得分 100+100+100+100=400. 
