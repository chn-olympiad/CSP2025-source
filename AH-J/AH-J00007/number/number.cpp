#include <cstdio>
#include <algorithm>
using namespace std;
char s[1000005];
int h[1000005],cnt;
int main(void) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;s[i]!='\0';++i)
		if(s[i]>='0'&&s[i]<='9') h[cnt++]=s[i]-'0';
	sort(h,h+cnt);
	for(int i=cnt-1;i>=0;--i) printf("%d",h[i]);
	return 0;
}
