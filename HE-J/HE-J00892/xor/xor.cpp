#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,k,numl[5001],ans=0;
string zhuaner(int num)
{
	string s;
	for(int i=0;i<=21;i++)
	{
		if(num%2==1)s='1'+s;
		else s='0'+s;
		num/=2;
	}
	return s;
}
string yihuo(string num1,string num2)
{
	string s;
	for(int i=0;i<=21;i++)
	{
		if(num1[i]==num2[i])s+='0';
		else s+='1';
	}
	return s;
}
int zhuanshi(string s)
{
	int num=0;
	for(int i=21;i>=0;i--)
	{
		if(s[i]=='1')
		{
			num+=pow(2,21-i);
		}
	}
	return num;
}
void DFS(int start,int count)
{
	if(count>ans)ans=count;
	for(;start<=n;start++)
	{
		for(int end=start;end<=n;end++)
		{
			string temp=zhuaner(numl[start]);
			for(int i=start+1;i<=end;i++)
			{
				temp=yihuo(temp,zhuaner(numl[i]));
			}
			if(zhuanshi(temp)==k)
			{
				DFS(end+1,count+1);
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>numl[i];
	}
	DFS(1,0);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
