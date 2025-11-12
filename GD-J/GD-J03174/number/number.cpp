#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N=1e6+10;
char s[N];
int n;
priority_queue<int> q;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		q.push(s[i]-'0');
	}
	while(q.size())
	{
		putchar(q.top()+'0');
		q.pop();
	}
	return 0;
} 
