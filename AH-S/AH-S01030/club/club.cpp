#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,sum=0;
        cin>>n;
        int b1=0,b2=0,b3=0;
        for(int j=1;j<=n;j++)
        {
            int x1,x2,x3;
            int ma=0;
            cin>>x1>>x2>>x3;
            if(x1>x2) ma=x1;
            else ma=x2;
            if(ma<x3)ma=x3;
            if(ma==x1)
            {
				if(b1<=n/2)
				{
					sum+=ma;
					b1++;
					continue;
				}
			}
			if(ma==x2)
            {
				if(b2<=n/2)
				{
					sum+=ma;
					b2++;
					continue;
				}
			}
			if(ma==x3)
            {
				if(b3<=n/2)
				{
					sum+=ma;
					b3++;
					continue;
				}
			}
        }
        cout<<sum<<endl;
    }
    return 0;
}

