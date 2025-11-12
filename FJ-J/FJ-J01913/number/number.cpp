#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1008611];
int a[1008611];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,ans=0;
	cin>>s;
	n=strlen(s);
	for(int u=0;u<n;u++){
		if(s[u]>='0'&&s[u]<='9')
		ans++,a[ans]=s[u]-'0';
	}
	sort(a+1,a+ans+1,cmp);
	for(int u=1;u<=ans;u++)
	cout<<a[u];
	return 0;
}
