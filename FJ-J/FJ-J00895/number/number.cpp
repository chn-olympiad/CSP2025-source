#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int a[MAXN],cnt=0;
char t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>t)
	{
		if(t>='0'&&t<='9'){
			a[++cnt]=t-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	return 0;
}
