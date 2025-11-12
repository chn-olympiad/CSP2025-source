#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
using namespace std;
const int MAX=1e6+10;
char str[MAX];
vector<char> a;
int n;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", str+1);
	n=strlen(str+1);
	for (int i=1;i<=n;i++) if (isdigit(str[i])) a.push_back(str[i]);
	sort(a.begin(), a.end(), greater<char>());
	for (auto ch:a) putchar(ch);
	return 0;
} 
