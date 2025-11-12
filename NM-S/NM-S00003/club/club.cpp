#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][5];
int a1[100010];
int ans;
bool A;
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	ans=0;
    	cin>>n;
    	A=1;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=3;j++)
    			cin>>a[i][j];
    		a1[i]=a[i][1];
		}

    	for(int i=1;i<=n;i++)
			if(a[i][2]!=0 or a[i][3]!=0)
				A=0;
		if(n==2)
		{
			ans=max(a[1][1]+a[2][2],ans);
			ans=max(a[1][1]+a[2][3],ans);
			ans=max(a[1][2]+a[2][1],ans);
			ans=max(a[1][2]+a[2][3],ans);
			ans=max(a[1][3]+a[2][1],ans);
			ans=max(a[1][3]+a[2][2],ans);
			cout<<ans<<endl;
		}
		else if(A)
		{
			sort(a1+1,a1+n+1);
			for(int i=1;i<=n/2;i++)
				ans+=a1[i];
			cout<<ans<<endl;
		}
	}
    return 0;
}
