#include <bits/stdc++.h>

using namespace std;

#define N 500005

int a[N];
bool b[N];

int n,k;

void aaa(int l,int r)
{
    int i;
    for(i=l;i<=r;i++)
        b[i]=1;
}

int check1(int l,int r)
{
    if(r<l)
    {
        return 0;
    }
    if(l==r)
    {
        return 0;
    }
    int ans=0;
    int i,j;
    for(i=l;i<r;i++)
    {
        if(b[i]==1)
        {
            continue;
        }
        int num=a[i];
        for(j=i+1;j<=r;j++)
        {
            num=(num^a[j]);
            if(num==k)
            {
                aaa(i,j);
                return check1(j+1,r)+1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int num=0;
    cin>>n>>k;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            b[i]=1;
            num++;
        }
    }
    int y=1;
    for(i=1;i<=n;i++)
    {
        if(b[i]==1)
        {
            if(b[i-1]!=1)
            {
                num+=check1(y,i-1);
                y=n;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(i<y)
            {
                y=i;
            }
        }
    }
    num+=check1(y,n);
    cout<<num<<endl;
    return 0;
}
