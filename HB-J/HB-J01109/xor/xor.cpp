#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],book[500005],t=1,ans;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)
	cin>>a[i];
int f=0;
for(int i=1;i<=n;i++)
{
	book[i]=a[i];
	for(int j=t;j<i;j++)
	{
		book[j]=book[j]^a[i];
		if(book[j]==k)
		{
			ans++;
			t=i+1;
			f=1;
		}
		if(f==1)
			break;
	}
	if(book[i]==k && f==0)
	{
		ans++;
		t=i+1;
	}
	f=0;
}
cout<<ans;
return 0;
}
