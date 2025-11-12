#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

int a[1000005],t,cnt;

int read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)&&ch!=EOF) ch=getchar();
	if(isdigit(ch)) return ch-48;
	else return -1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	while((t=read())!=-1) a[++cnt]=t;
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}