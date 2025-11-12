#include<algorithm> 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s,t;
char c;
int a[12]={0};
int main()
{
	freopen("number.in","s",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//scanf("%s",&s);
	//for(int i=0;i<=s.size()-1;i++)/*
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	int j=0;
	for(int i=9;i>=0;i--)
	{
		for(int k=1;k<=a[i];k++) 
		{
			//t[j]=i;
			//j++;
			printf("%d",i);
		}
		//cout<<a[i]<<" ";	
	}
	//cout<<t;
	return 0;
}