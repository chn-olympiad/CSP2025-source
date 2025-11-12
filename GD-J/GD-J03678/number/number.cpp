#include <bits/stdc++.h> 
using namespace std;
char a[1000006];
char c[1000005];
bool cmp(char x,char y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int cnt=1;
	for(int i=1;i<=len;i++)
	{
		a[i]=s[i-1];
	}
	for(int i=1;i<=len;i++)
	{
		int x=a[i];
		x=int(x);
		if(x>40 && x<97)
		{
			c[cnt]=a[i];
			cnt++;
		}
	}
	sort(c+1,c+cnt,cmp);
	for(int i=1;i<=cnt-1;i++)
	{
		cout<<c[i];
	}
	return 0;
}
