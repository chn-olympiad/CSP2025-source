//超绝思路一命速通 
//过于简单了 
//先将数字提取出来 
//然后从大到小排序输出 
//什么?全是0怎么办 
//题目说不会全是0
//至少有个1~9的数字 

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +5;//数据有10^6 
string s;
int a[N],cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1,a + cnt + 1,cmp);//从大到小排序 
	for(int i = 1;i <= cnt;i++){
		printf("%d",a[i]);//10^6数据，cout复杂度神秘炸掉 
	}
	return 0;
}

