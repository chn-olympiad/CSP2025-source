#include<iostream>
//#include<cmath>
//#include<algorithm>
//#include<string>
#include<cstdio>
using namespace std;
int a[15];
int main(){
	string str;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if((int)str[i]>=48&&(int)str[i]<=57)a[(int)str[i]-48]++;

	}
//	for(int i=1;i<=9;i++)
//	{
//		cout<<i<<":"<<a[i]<<"¸ö"<<endl;
//	}

	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
			
		}
	}
	
	return 0;
}
