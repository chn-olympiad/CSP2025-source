#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long t;
long long n[N],a[N],cch[N],x1[N],x2[N],x3[N];
long long c1,c2,c3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	x1[0]=0;
	x2[0]=0;
	x3[0]=0;
	for(int i=1;i<=t;i++)
	{cin>>n[i];
		for(int k=1;k<=n[i];k++)
		{
		for(int j=1;j<=3;j++)
		{		
			cin>>a[j];	
			cch[j]=max(a[j-2],max(a[j-1],a[j]));
			cch[1]=cch[j]+cch[j-1];
				
		}
		}
		
	cout<<cch[1];

	
}

			
		

	return 0;
}
