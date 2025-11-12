#include<bits/stdc++.h>
using namespace std;
#define N 1000000
long long cnt1=0, n,a[N],k;
bool flag[N];
bool fun(int x,int y)
{long long cnt=0;
	for(int b=x;b<=y;b++)
	{
		cnt=cnt^a[b];
		if(flag[b])return false;
	}
	if(cnt!=k)return false;
	return true;
}
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
for(int i=0;i<n;i++)
{
	for(int j=i;j<n;j++)
	{
		if(fun(i,j))
		{cnt1++;
		for(int l=i;l<=j;l++)flag[l]=true;
		}
	}
}
cout<<cnt1<<endl;
return 0;
}
