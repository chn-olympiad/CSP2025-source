#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int l,int r)
{
	return l>r;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	int len=1;
	cin>>x;
	while(x!='\n')
	{
		if(x>='0'&&x<='9') a[len++]=x-'0';
		scanf("%c",&x);
	}
	sort(a+1,a+len,cmp);
	for(int i=1;i<len;i++) printf("%d",a[i]);
	return 0;
}
