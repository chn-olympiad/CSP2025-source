#include <bits/stdc++.h>
using namespace std;
int n=0;int a[1000086];int l;
string s;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			continue;
		}
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=(s[i]-'0');
			
		}
	}
	sort(a+1,a+n+1,cmp);//把数据预处理一下，然后sort排个列就结束了 
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
