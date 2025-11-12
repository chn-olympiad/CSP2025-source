#include<bits/stdc++.h>
using namespace std;
char s[1000050];
int a[1000050];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s),m=0;
	for(int i=0;i<n;i++) {
		if(s[i]>='0'&&s[i]<='9')
		{
			a[m++]=s[i]-48;
		}
	}
	sort(a,a+m);
	for(int i=m-1;i>=0;i--) {
		printf("%d",a[i]);
	}
	return 0;
}
