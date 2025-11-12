#include <cstdio>
#include <algorithm>
using namespace std;
char a[1000005];
int t[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	for(int i=0;a[i];i++)
		if(a[i]>='0'&&a[i]<='9')	t[cnt++]=a[i]-'0';
	sort(t,t+cnt);
	for (int i=cnt-1;i>=0;i--)	printf ("%d",t[i]);
	return 0;
}
