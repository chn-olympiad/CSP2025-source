#include <bits/stdc++.h>

using namespace std;

bool p(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str,str2;
	cin>>str;
	long n=str.size(),a[n],m=0;
	for(long i=0;i<n;++i)
	{
		str2=str.substr(i,1);
		int x=atoi(str2.c_str());
		if((x==0&&str2=="0")||x!=0)
		{
			a[m]=x;
			++m;
		}
	}
	sort(a,a+m,p);
	for(long i=0;i<m;++i)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	return 0;
}
