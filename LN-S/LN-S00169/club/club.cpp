#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int a[100005][4],tmp[100005];
int check_a,check_b;
int mx;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        check_a=1;
        check_b=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0 || a[i][3]!=0) check_a=0;
            if(a[i][3]!=0) check_b=0;
        }
        if(check_a)
        {
            for(int i=1;i<=n;i++)
            {
                tmp[i]=a[i][1];
            }
            sort(tmp+1,tmp+1+n);
            k=n/2;
            for(int i=n;i>k;i--)
            {
                mx+=tmp[i];
            }
        }

        else if(check_b)
        {
            k=n/2;
            for(int i=1;i<=n;i++)
            {
                tmp[i]=a[i][2]-a[i][1];
                mx+=a[i][1];
            }
            sort(tmp+1,tmp+1+n);
            for(int i=n;i>k;i--)
            {
                mx+=tmp[i];
            }
        }
        else
        {
            if(n==2)
            {
                int a1=a[1][1]+a[2][2];
                int a2=a[1][1]+a[2][3];
                int b1=a[1][2]+a[2][1];
                int b2=a[1][2]+a[2][3];
                int c1=a[1][3]+a[2][2];
                int c2=a[1][3]+a[2][1];
                mx=max(max(a1,a2),max(max(b1,b2),max(c1,c2)));
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    mx+=max(max(a[i][1],a[i][2]),a[i][3]);
                }
            }
        }

        cout<<mx<<endl;
    }

    return 0;
}
