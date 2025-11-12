#include<bits/stdc++.h>
using namespace std;
string a;
int n=0,ans[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (int i=0;i<a.size();++i)
	{
		if(a[i]>='0'&&a[i]<='9') ans[++n]=a[i]-'0';
	}
	sort(ans+1,ans+n+1);
	for (int i=n;i>=1;--i)
	  cout<<ans[i];
	cout<<endl;
	return 0;
}
