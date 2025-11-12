#include<bits/stdc++.h>
using namespace std;
bool qwe (int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,c;
	cin>>a;
	int a1=a.size(),b[a1]={ },q1=0;
	for(int i=0;i<a1;i++)
	{
		c=a[i];
		if(c=="0")
		{
			b[q1]=0;
			q1++;
		}else if(c=="1")
		{
			b[q1]=1;
			q1++;
		}else if(c=="2")
		{
			b[q1]=2;
			q1++;
		}else if(c=="3")
		{
			b[q1]=3;
			q1++;
		}else if(c=="4")
		{
			b[q1]=4;
			q1++;
		}else if(c=="5")
		{
			b[q1]=5;
			q1++;
		}else if(c=="6")
		{
			b[q1]=6;
			q1++;
		}else if(c=="7")
		{
			b[q1]=7;
			q1++;
		}else if(c=="8")
		{
			b[q1]=8;
			q1++;
		}else if(c=="9")
		{
			b[q1]=9;
			q1++;
		}
	}
	sort(b,b+a1,qwe);
	for(int i=0;i<q1;i++)
	{
		cout<<b[i];
	}
	return 0;
}
