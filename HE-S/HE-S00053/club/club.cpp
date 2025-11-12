#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int a[201],b[201],c[201],max=0,sum=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			max=a[j];
			if(b[j]>max)	max=b[j];
			if(c[j]>max)	max=c[j];
			sum+=max;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
