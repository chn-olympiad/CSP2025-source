#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000],h=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	while(len--)
		if('0'<=s[len]&&s[len]<='9')
			a[h++]=s[len]-48;
	sort(a,a+s.size(),cmp);
	for(int i=0;i<h;i++)
		cout<<a[i];
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
