#include<bits/stdc++.h>
using namespace std;
int t;
int b1,b2,b3;
int a[100005],b[100005],c[100005];
int sum =0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout;

	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int m = n/2;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++)
		{
			int maxn = max(c[i],max(a[i],b[i]));
			sum+=maxn;
		}
		cout<<sum<<endl;
		sum = 0;
	} 	
	return 0;
}
