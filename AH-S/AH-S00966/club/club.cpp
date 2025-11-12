#include<bits/stdc++.h>
using namespace std;
int a[100001][3],m[3][100001],sum=0,idx1=0,idx2=0,idx3=0;
void s(int s[],int n)
{
    int m;
    for(int i=1;i<n;i++)    if(s[i]<s[0]&&s[i+1]>s[0])
    {
        m=i;
        break;
    }
    s[m]=s[0];
    for(int i=1;i<m;i++)
    {
        s[i-1]=s[i];
    }
}
void f(int x,int y)
{
    if(x==0)    s(m[x],idx1);
    else    if(x==1)    s(m[x],idx2);
    else    s(m[x],idx3);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)    for(int j=0;j<3;j++)    cin>>a[i][j];
        sum=0,idx1=0,idx2=0,idx3=0;
        for(int i=0;i<n;i++)
        {
            int k=max(a[i][0],max(a[i][1],a[i][2]));
            if(k==a[i][0]&&idx1==n/2)
            {
                int k1=k-max(a[i][1],a[i][2]);
                if(m[0][0]<=k1)
                {
                    sum=sum-m[0][0]+k;
                    m[0][0]=k1;
                    f(0,0);
                }
                else    if(k-k1==a[i][1])
                {
                    sum+=a[i][1];
                    m[1][idx2++]=k-a[i][1];
                    f(1,idx2-1);
                }
                else    if(k-k1==a[i][2])
                {
                    sum+=a[i][2];
                    m[2][idx3++]=k-a[i][2];
                    f(2,idx2-1);
                }
            }
            else    if(k==a[i][1]&&idx2==n/2)
            {
                int k1=k-max(a[i][0],a[i][2]);
                if(m[1][0]<=k1)
                {
                    sum=sum-m[1][0]+k;
                    m[1][0]=k1;
                    f(1,0);
                }
                else    if(k-k1==a[i][0])
                {
                    sum+=a[i][0];
                    m[0][idx1++]=k-a[i][0];
                    f(0,idx1-1);
                }
                else    if(k-k1==a[i][2])
                {
                    sum+=a[i][2];
                    m[2][idx3++]=k-a[i][2];
                    f(2,idx2-1);
                }
            }
            else    if(k==a[i][2]&&idx3==n/2)
            {
                int k1=k-max(a[i][0],a[i][1]);
                if(m[2][0]<=k1)
                {
                    sum=sum-m[2][0]+k;
                    m[2][0]=k1;
                    f(2,0);
                }
                else    if(k-k1==a[i][0])
                {
                    sum+=a[i][0];
                    m[0][idx1++]=k-a[i][0];
                    f(0,idx1-1);
                }
                else    if(k-k1==a[i][1])
                {
                    sum+=a[i][1];
                    m[1][idx2++]=k-a[i][1];
                    f(1,idx2-1);
                }
            }
            else
            {
                if(k==a[i][0])
                {
                    int k1=max(a[i][1],a[i][2]);
                    m[0][idx1++]=a[i][0]-k1;
                    sum+=a[i][0];
                    f(0,idx1-1);
                }
                else    if(k==a[i][1])
                {
                    int k1=max(a[i][0],a[i][2]);
                    m[1][idx2++]=a[i][1]-k1;
                    sum+=a[i][1];
                    f(1,idx2-1);
                }
                else
                {
                    int k1=max(a[i][0],a[i][1]);
                    m[2][idx3++]=a[i][2]-k1;
                    sum+=a[i][2];
                    f(2,idx3-1);
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
