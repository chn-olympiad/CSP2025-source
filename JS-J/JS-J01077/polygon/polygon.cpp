#include<bits/stdc++.h>
using namespace std;

int a[10001],b[10001];
long long  n,s=0,ans=0;
int aaa(int x,int y,int z)
{
	for(int i=x;i<n;i++)
	{
		z++;
		if(a[i]+y>a[n]&&z>=2)
		{
			ans+=1;
			ans%=998224353;
			}
			if(i+1<=n)
			{
				aaa(i+1,y+a[i],z);
			}
			else 
			return 0;
	}
	return 0;
}

int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

cin>>n;

for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a,a+n+1);
for(;n>=3;n--)
aaa(1,0,0);
cout<<ans;
return 0;
}
