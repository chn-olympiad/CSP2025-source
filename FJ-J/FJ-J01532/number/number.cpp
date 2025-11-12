#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 1e6+5;
char ch[N];
int cnt[100]; 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", ch);
	int len = strlen(ch);
	rep(i, 0, len - 1)
		if('0' <= ch[i] && ch[i] <= '9') cnt[ch[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		while(cnt[i]--) printf("%d", i);
	return 0;
}
