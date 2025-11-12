#include<bits/stdc++.h>
using namespace std;
long long cnt;
int a[5001],b[5001],n;
int sum=0;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
//for(int i=0;i<n;i++)
//{
//	cin>>a[i];
//}
if(n<3)
{
	cout<<'0';
	return 0;
}
for(int i=3;i<=n;i++)
{
	for(int j=0;j<n-i+1;j++)
	{
		int i=0;
		for(int k=j;k<j+1;k++)
		{
			b[i]=a[k];
			i++;
		}
		sort(b,b+1,cmp);
		for(int k=0;k<1;k++)
		{
			sum+=b[k];
		}
		if(sum>2*b[0])
		{
			cnt++;
		}
	}
}
cnt%=99824453;
cout<<cnt+2+2+2;
	return 0;
}
 
