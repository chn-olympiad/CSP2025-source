#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	long long nn=1,sn=str.length();
	for(int i=0;i<=sn;i++){
		if(str[i]>='0' && str[i]<='9')
		{
			a[nn]=str[i]-'0';
			nn++;
		}
	}
	sort(a+1,a+nn+1,greater<int>());
	for(int i=1;i<=nn-1;i++)
	{
		cout<<a[i];
	}
	return 0;
}
