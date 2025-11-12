#include <bits/stdc++.h>

using namespace std;
int a[500000];
long long n,k;
int cnt;
bool pd(int l,int r)
{
    int ans=0;
    int count1=0;
    if(l==r)
    {
        ans=a[l]|a[l];
        count1++;
    }
    for(int i=l;i<=r;i++)
    {

        if(i<n&&a[i]!=-1)
        {
            count1++;
            ans=(ans|a[i]);
        }


    }
    if(ans==k&&count1!=0)
        return true;
    return false;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int c=0;

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            bool pdd=pd(j,j+c);
            cnt+=pdd;
            if(pdd==true)//fanfu
            {
                for(int k=j;k<=j+c;k++)
                    a[k]=-1;
            }

        }
        c++;
    }
    cout<<cnt;
    return 0;
}
