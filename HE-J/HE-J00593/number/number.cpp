#include<cstdio>
#include<cstring>
#include<algorithm>

const int N=1e6+1*6;
char a[N];
int c[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++) if(a[i]>='0'&&a[i]<='9') c[++cnt]=a[i]-'0';
	std::sort(c+1,c+1+cnt);
	for(int i=cnt;i>=1;i--) printf("%d",c[i]);
	return 0;
}
