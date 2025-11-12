#include<bits/stdc++.h>		//#Shang4Shan3Ruo6Shui4
using namespace std;
const int MAXN=1e6+5;
char s[MAXN];
int n;
priority_queue<int,vector<int>,less<int> > q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			q.push(s[i]-'0');
	while(!q.empty())
	{
		printf("%d",q.top());
		q.pop();
	}
	return 0;
}
