#include<bits/stdc++.h>
using namespace std;
int t,n,bg;
int yibu=0,erbu=0,sanbu=0;
long long num=0;
int a[100005][5],m1[100005],m2[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        bg=n/2;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<3;k++)
            {
                cin>>a[j][k];
            }
        }
        for(int j=0;j<n;j++)
        {
            m1[j]=max(a[j][0],a[j][1]);
            m1[j]=max(m1[j],a[j][2]);
            if(m1[j]==a[j][0])
            {
                if(a[j][1]<=m1[j]&&a[j][1]>=a[j][2])
                    m2[j]=a[j][1];
                else if(a[j][2]<=m1[j]&&a[j][2]>=a[j][1])
                    m2[j]=a[j][2];
            }
            if(m1[j]==a[j][1])
            {
                if(a[j][0]<=m1[j]&&a[j][0]>=a[j][2])
                    m2[j]=a[j][0];
                else if(a[j][2]<=m1[j]&&a[j][2]>=a[j][0])
                    m2[j]=a[j][2];
            }
            if(m1[j]==a[j][2])
            {
                if(a[j][1]<=m1[j]&&a[j][1]>=a[j][0])
                    m2[j]=a[j][1];
                else if(a[j][0]<=m1[j]&&a[j][0]>=a[j][1])
                    m2[j]=a[j][0];
            }
        }
        sort(m1+1,m1+1+n);
        for(int j=0;j<bg;j++)
        {
            if(n==2)
            {
                if(m1[0]==a[0][0]||m1[0]==a[0][1]||m1[0]==a[0][2])
                {
                    num+=m1[0];
                    num+=m2[1];
                }
                else if(m1[0]==a[1][0]||m1[0]==a[1][1]||m1[0]==a[1][2])
                {
                    num+=m1[0];
                    num+=m2[0];
                }
            }
        }
        for(int j=1;j<=bg;j++)
        {
        	if(n!=2)
        		num+=m1[i];
		}
        cout<<num;
    }
    return 0;
}

