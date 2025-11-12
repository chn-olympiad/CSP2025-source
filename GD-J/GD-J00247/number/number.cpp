#include<bits/stdc++.h>
using namespace std;
char a[1000601];
long long n;
priority_queue<long long> q;
void fre()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{
	fre();
	scanf("%s",a+1),n=strlen(a+1);
	for(long long i=1;i<=n;i++)
		if(a[i]>='0'&&a[i]<='9')
			q.push(a[i]-'0');
	while(!q.empty()) cout<<q.top(),q.pop();
	return 0;
}
