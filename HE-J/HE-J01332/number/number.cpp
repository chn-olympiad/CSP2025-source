#include<iostream>
#include<algorithm>
using namespace std;
void Ch(char ch[])
{
	int t,num=0,a[1001];
	for(int i=0;ch[i]!=0;i++)
	{
			t=((int)ch[i]);
			if(t>=48&&t<=57)
			{
				a[num]=t-48;
				num++;
			}
	}
	for(int i=0;i<=num;i++)
	{
		for(int j=0;j<=num-1;j++)
		{
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<num;i++)
		cout<<a[i];
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1001],num=0,t;
	char ch[1001];
	for(int i=1;i<=1001;i++)
	{
		ch[i]=0;
	}
	cin>>ch;
	Ch(ch);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
