#include<bits/stdc++.h>
using namespace std;
char s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(true)
	{
		s=getchar();
		if(s==EOF) break;
		if(s<97) a[s-48]++;
	}
	for(int i=9;i>=0;i--)
		while(a[i]) cout<<i,a[i]--;
	return 0;
}
