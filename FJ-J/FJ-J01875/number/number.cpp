// T1 AC
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
char c[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c + 1); n = strlen(c + 1);
	multiset<char> S;
	for(int i = 1; i <= n; i++) if(c[i] >= '0' && c[i] <= '9') S.insert(c[i]);
	stack<char> st;
	for(char i : S) st.push(i);
	while(!st.empty()) putchar(st.top()),st.pop();
	cout << endl;
	return 0;
}

