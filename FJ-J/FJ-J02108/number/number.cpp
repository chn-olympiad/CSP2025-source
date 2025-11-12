//终于还是到了这一刻吗。 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m=0;
int x[N];
char s[N];
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			x[++m]=s[i]-'0';
	sort(x+1,x+m+1,cmp);
	for(i=1;i<=m;i++)
		printf("%d",x[i]);
	return 0;
}
