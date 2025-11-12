#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string str;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	if(str[i]>='0'&&str[i]<='9')a[++n]=str[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}

