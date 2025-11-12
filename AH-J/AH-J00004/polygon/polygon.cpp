#include <iostream>
#include <algorithm>

using namespace std;

const int N=5010;
int n;
int a[N],s[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	int i=1,j=3,ans=0;
	while(i<=n&&j<=n&&(i-j+1)>=3)
	{
		while((i-j+1)<3)j++;
		if((s[j]-s[i-1])>2*a[j])
		{
			ans++;
			j++;
		}
		else i=j;
		for(int k=1;k<=n;k++)
		{
			if(k<i)
				if((s[j]-s[i-1]+a[k])>a[j]*2)ans++;
			if(k>j)
				if((s[j]-s[i-1]+a[k])>a[k]*2)ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
