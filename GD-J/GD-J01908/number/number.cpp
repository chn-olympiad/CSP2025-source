#include<cstdio>
#include<algorithm>
#define N 1000005
char s[N], c, a[N];
int n;
bool cmp(char x, char y){
	return x > y;
}
int main(){
	int i;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s+1);
	for(i=1; c=s[i]; i++)
		if(c>='0' && c<='9') a[++n] = c;
	std::sort(a+1, a+n+1, cmp);
	for(i=1; c=a[i]; i++) printf("%c", c);
	fclose(stdin); fclose(stdout);
	return 0;
}//Ô¤²â100 
