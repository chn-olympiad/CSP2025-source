#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000005];
int len=0;
bool cmp(const char& a,const char& b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	sort(s,s+len,cmp);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') printf("%c",s[i]);
	}
	return 0;
} 
