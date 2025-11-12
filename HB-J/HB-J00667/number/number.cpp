#include<bits/stdc++.h>
using namespace std;
#define love return
#define sugary 0//神秘爱好小代码
char s[100009];
int num[100009];
int cnt = 0;//数字位数
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 0; i <= 100008; i++) num[i] = 0;
	for(int i = 1; i <= 100008; i++) cin >> s[i];
	for(int i = 0; i <= 100009; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			num[cnt] = s[i] - '0';
		}
	}
	//cout << s;
	sort(num + 1, num + cnt + 1);
	
	for(int i = cnt; i >= 1; i--){
		cout << num[i];
	}
	love sugary;
}
