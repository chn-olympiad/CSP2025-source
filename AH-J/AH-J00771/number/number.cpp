#include<stdio.h>
#include<string.h>
char c[1000002],l;
int t[63];
int main() {
	freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
	fgets(c,1000002,stdin),l=strlen(c);
	for(int i=0; i<l; ++i)
		if(c[i]>=48&&c[i]<=57)
			++t[c[i]];
	for(int i=63; i>=0; i--)
		while(t[i])
			putchar(i),--t[i];
	return 0;
}
