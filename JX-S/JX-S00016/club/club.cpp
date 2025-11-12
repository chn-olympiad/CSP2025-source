#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][10],b1[100010][10],b2[100010][10],b3[100010][10],s1[100010],s2[100010],s3[100010];
int ex[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int l1=0,l2=0,l3=0;
        long long sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                l1++;
                b1[l1][2]=a[i][1]-a[i][2];
                b1[l1][3]=a[i][1]-a[i][3];
                s1[l1]=a[i][1];
            }
            else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1])
            {
                l2++;
                b2[l2][1]=a[i][2]-a[i][1];
                b2[l2][3]=a[i][2]-a[i][3];
                s2[l2]=a[i][2];
            }
            else
            {
                l3++;
                b3[l3][1]=a[i][3]-a[i][1];
                b3[l3][2]=a[i][3]-a[i][2];
                s3[l3]=a[i][3];
            }
        }
        for(int i=1;i<=l1;i++)
                sum+=s1[i];
        for(int i=1;i<=l2;i++)
                sum+=s2[i];
        for(int i=1;i<=l3;i++)
                sum+=s3[i];
        if(l1<=n/2&&l2<=n/2&&l3<=n/2)
        {
            cout<<sum<<endl;
        }
        else if(l1>n/2)
        {
            for(int i=1;i<=l1;i++)
            {
                ex[i]=min(b1[i][2],b1[i][3]);
            }
            sort(ex+1,ex+l1+1);
            for(int i=1;i<=l1;i++)
            {
                sum-=ex[i];
                l1--;
                if(l1==n/2)
                    break;
            }
            cout<<sum<<endl;
        }
        else if(l2>n/2)
        {
            for(int i=1;i<=l2;i++)
            {
                ex[i]=min(b2[i][1],b2[i][3]);
            }
            sort(ex+1,ex+l2+1);
            for(int i=1;i<=l2;i++)
            {
                sum-=ex[i];
                l2--;
                if(l2==n/2)
                    break;
            }
            cout<<sum<<endl;
        }
        else if(l3>n/2)
        {
            //cout<<1<<endl;
            for(int i=1;i<=l3;i++)
            {
                ex[i]=min(b3[i][1],b3[i][2]);
                //cout<<ex[i]<<" "<<i<<endl;
            }
            sort(ex+1,ex+l3+1);
            for(int i=1;i<=l3;i++)
            {
                sum-=ex[i];
                l3--;
                if(l3==n/2)
                    break;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
