#include<iostream>
#include<algorithm>
using namespace std;
short a[1000005];
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char c;
	while(scanf("%c",&c)!=EOF)
		if(c>='0' && c<='9')
			a[n++]=(c-'0');

	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++) printf("%d",a[i]);
	
	fclose(stdin); fclose(stdout);
	return 0; 
}
