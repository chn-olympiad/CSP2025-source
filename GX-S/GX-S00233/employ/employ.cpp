#include<bits/stdc++.h>

using namespace std;

int n,m,person,decide;
int a[10000],b[10000],p[10000],q[10000];
string hard;

void cf(int l)
{
    for(int i=l;i<=n;i++)
    {
        q[i]=q[i-1]-1;
        if(q[i]+p[i]==0)
            cf(i);
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>hard;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        p[i]=b[i]-b[i-1];
        q[i]=q[i-1]+p[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            /*for(int k=0;k<hard.size();i++)
            {
                if(hard[i]=='0')
                {
                    cf(k);
                }
            }*/
            for(int k=1;k<=n;k++)
            {
                if(q[k]+p[k]>0)
                    person++;
            }
            if(person>=m)
                decide++;
            swap(b[i],b[j]);
            for(int k=1;k<=n;k++)
            {
                p[i]=b[i]-b[i-1];
                q[i]=q[i-1]+p[i];
            }
        }
    }
    cout<<decide;
    return 0;
}
