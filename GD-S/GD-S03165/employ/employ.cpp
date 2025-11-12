#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],deny;
int jc(int n)//½×³Ë 
{
	int ans=1;
	for(int i=2;i<=n;++i)
	ans*=i;
	
	return ans; 
}
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int a[505];
	for(int i=0;i<n;++i)
	{
		cin>>c[i];
		a[i]=s[i];
	}
	sort(c,c+n);
	sort(a,a+n);
	int ans=0,ct=1;
	for(int i=0;i<n-1;++i)
	{
		if(c[i]==c[i+1])
		{
			++ct;
		}
		else if(ct>1)
		{
			ans+=jc(ct);
			ct=1;
		}
	}
	ct=1;
	int ans2=0;
	for(int i=0;i<n-1;++i)
	{
		if(a[i]==a[i+1])
		{
			++ct;
		}
		else if(ct>1)
		{
			ans2+=jc(ct);
			ct=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


