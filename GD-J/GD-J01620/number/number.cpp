#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int num=0;
	cin>>n;
	for(int i=0;i<sizeof(n);i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			int h=n[i]-'0';
			num++;
			a[num]=h;
		}
	}
//	cout<<num<<endl;
	sort(a+1,a+num+1);
	while(num>=1)
	{
		cout<<a[num];
		num--;
	}
	return 0;
 } 
