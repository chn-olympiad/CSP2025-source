#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010];
int a[1000010];
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0,sum=0;
	for(;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[sum]=int(s[i]-'0');
			sum++;
		}
	}
	sort(a,a+sum);
	sum--;
	for(;sum>=0;sum--)
	cout<<a[sum];
	return 0;
}
