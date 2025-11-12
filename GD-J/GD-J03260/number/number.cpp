#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1919810],b[1919810];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int n = strlen(a+1);
	int m = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= '0' && a[i] <= '9')
			b[++m] = a[i];
	sort(b+1,b+m+1,[](char a, char b) {
		return a > b;
	});
	puts(b+1);
	return 0;  
}

/*
Today's GXR's birthday.
But it's not possible to go to 'er party
:(拼尽全力无法 AK.png)

// freopen().jpg

*/
