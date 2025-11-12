#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100010] = {0},s[100010] = {'\0'};
bool cmp(char,char);
int main()
{
	freopen(&"number.in"[0],&"r"[0],stdin);
	freopen(&"number.out"[0],&"w"[0],stdout);
	scanf(&"%s"[0],&s[1]);
	int l = 0,n = (int)(strlen(&s[1]));
	for(int i = 1;i <= n;i = i + 1)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			l = l + 1;
			a[l] = s[i];
		}
	}
	std::stable_sort(&a[1],&a[l + 1],cmp);
	printf(&"%s"[0],&a[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(char a,char b)
{
	if(a > b)
	{
		return true;
	}
	return false;
}
