#include<iostream>
#include<algorithm>
#include<string>
bool cmp(int a,int b)
{
	return a>b;
}
std::string s;
long long a[1005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	long long l=s.size(),cnt=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0')a[cnt]=0;
		else if(s[i]=='1')a[cnt]=1;
		else if(s[i]=='2')a[cnt]=2;
		else if(s[i]=='3')a[cnt]=3;
		else if(s[i]=='4')a[cnt]=4;
		else if(s[i]=='5')a[cnt]=5;
		else if(s[i]=='6')a[cnt]=6;
		else if(s[i]=='7')a[cnt]=7;
		else if(s[i]=='8')a[cnt]=8;
		else if(s[i]=='9')a[cnt]=9;
		if(s[i]>='0'&&s[i]<='9')cnt++;
	}
	std::sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)
		std::cout<<a[i];
	std::cout<<std::endl;
	return 0;
}
