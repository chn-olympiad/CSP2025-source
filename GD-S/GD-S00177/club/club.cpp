#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005],c[100005],b[100005];
int cnt,ans[35][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		//输入； 
		cnt=0;
		sort(a+1,a+n+1);
		for(int j=n;j>n/2;j--)
		{
			cnt+=a[j];
		}
		cout<<cnt<<endl;
		//特殊性质A； 
	}
	return 0;
} 
