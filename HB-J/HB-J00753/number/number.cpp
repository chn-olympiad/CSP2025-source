#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000],lena;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i=0;i<int(s.length());i++)
		if ('0'<=s[i]&&s[i]<='9') a[++lena]=(s[i]-'0');
	sort(a+1,a+lena+1,cmp);
	for (int i=1;i<=lena;i++)
		printf("%d",a[i]);
	return 0;
}
