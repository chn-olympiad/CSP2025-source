#include<bits/stdc++.h>
using namespace std;
char a[1000005],s;
int n=1;
bool cmp(char x,char y)
{
		return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
		if(s<'a')
			a[n++]=s;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++)
		cout<<a[i];
	return 0;
}
