#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(isdigit(s[i]))
		{
			a[i]=s[i]-48;
			n++; 
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<=n-1;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
