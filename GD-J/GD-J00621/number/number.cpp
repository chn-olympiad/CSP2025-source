#include<bits/stdc++.h>
using namespace std;
int a[1000055];
int k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	while(cin>>x)
	{
		if(x>='0'&&x<='9')
		{
			a[k++]=x-'0';
		}
	}
	sort(a,a+k,cmp);
	int i=0;
	for(;i<k-1;i++)if(a[i]!=0)break;
	for(;i<k;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
