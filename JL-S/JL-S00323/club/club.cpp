#include<bits/stdc++.h>
using namespace std;
int k[100][100];
long long maxn=100000;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int l;
    cin>>l;
    for(int u=0;u<l;u++)
    {
    int n;
    cin>>n;
    long long ans=0;
    if(n>200)
    {
		int a,b,u[n];
		for(int ol=0;ol<n;ol++)
		{
			cin>>u[ol]>>a>>b;
		}
		for(int y=0;y<n;y++)
		{
			for(int q=y+1;q<n;q++)
			{
				if(u[y]<u[q])
				{
					swap(u[y],u[q]);}
			}
		}
		for(int q=0;q<n/2;q++)
		{
			ans+=u[q];
			}
	}
	else
	{
    for(int y=1;y<=n;y++)
     {
        for(int r=1;r<=3;r++)
        {
        cin>>k[y][r];
        }
    }
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        for(int r=1;r<=3;r++)
        {
            if(r!=i&&k[1][i]+k[2][r]>ans)
            {
                ans=k[1][i]+k[2][r];
            }
        }
    }
    cout<<ans<<endl;
}
    }
}

