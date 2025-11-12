#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int ans[N],tot;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' ||a[i]=='8'||a[i]=='9'||a[i]=='0')
		{
			ans[++tot]=a[i]-'0';
		}
	}
	sort(ans+1,ans+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		printf("%d",ans[i]);
	}
}
