#include<bits/stdc++.h>
using namespace std;
long long s[1000002];
char a;
long long len=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;;)
	{
		a=getchar();
		if(a=='\n')
		{
//			cout<<"chulaile";
			break;
		}
		else
		{
//			cout<<"a="<<a-'0';
//			cout<<"i="<<i;
			if(a-'0'>=0 && a-'0'<=9)
			{
				i++;
				s[i]=a-'0';
				len++;
			}
		}
	}
//	//--------------debug
//	for(int i=1;i<len;i++)
//	{
//		cout<<s[i];
//	}
//	//------------
	sort(s+1,s+len,cmp);
//	cout<<"-----------";
	for(int i=1;i<len;i++)
	{
//		cout<<s[i];
		printf("%lld",s[i]);//time
	}
	return 0;
}
