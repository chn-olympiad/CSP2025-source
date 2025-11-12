#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char s[MAXN];
int ans[MAXN];
bool cmp(int a, int b){
	return a > b;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ans[cnt] = int(s[i] - '0');
			cnt++;
		}
	}
	sort(ans, ans + cnt, cmp);
	if(ans[0] == 0){
		printf("0");
		return 0;
	}
	for(int i = 0; i < cnt; i++){
		printf("%d", ans[i]);
	}
    return 0;
}
