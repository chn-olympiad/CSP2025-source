#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int a[N],p;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(1){
		c=getchar();
		if(c>='0' && c<='9')	a[++p]=(int)c;
		if(c=='\n')	break;
	}
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--)	putchar(a[i]);
	return 0;
}
