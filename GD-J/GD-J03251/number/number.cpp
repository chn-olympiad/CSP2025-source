#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char s[N];
int n, cnt[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i = 1; i <= n; i++){
		if('0' <= s[i] && s[i] <= '9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		while(cnt[i]--) printf("%d", i);
	}
	return 0;
} 
/*
CSP-J 乐子人大赏
freoepn()
freopne() 

我是整活人

但是考试到一半头晕不舒服到校医室享受了优质睡眠

后面忘了前面忘了中间忘了 
*/ 
