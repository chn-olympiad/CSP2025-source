#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=1e6+5;
char s[N];
int a[13];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf ("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++) 
		if (s[i]>='0' && s[i]<='9')
			a[s[i]-'0']++;
	for (int i=9;i>=0;i--) {
		if (a[i]>0) {
			while (a[i]--) printf("%d",i);
		}
	}
	return 0;
}
