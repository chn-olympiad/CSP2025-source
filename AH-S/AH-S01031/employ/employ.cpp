#include<bits/stdc++.h>
using namespace std;
bool pd(char c)
{
	if(c=='1'）
	return 1;
	if(c=='0')
	return 0;
}
int mount(int k,,int top,int pi,int,qi,int,js)
{
	for(k=0;;k<top;k++)
	{
		if((pd(pi))&&(qi>=(k+1))
		js++;
	}
	return js;
}
int main()
{
	freopen("enploy.in","r",stdin);
    freopen("enploy.out","w",stdout);
	int n,m;
	int a[100010];
	cin>>n>>m;
	string s[10010];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int a[100010];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		if(mount(i,n,s[i],a[i])>=m)
		ans++;
	else
	{
		for(int i=0;i<n-1;i++)
		{
			int prep;
			prep=s[i];
			s[i]=s[i+1];
			s[i+1]=prep;
			if(mount(j,n,s[j],a[j])>=m)
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
    return 0;
}
