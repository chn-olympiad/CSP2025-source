#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
string a;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	cin>>a;
	int len=a.size()-1;
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<=len+1;i++)
	{
		if(a[i]>='0' and a[i]<='9')
		{
			cout<<a[i]; 
		}
	}
	return 0;
}
