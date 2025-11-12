#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int qzh[N],arr[N];
int n,k;
int qu(int i,int j)
{
    return qzh[j]^qzh[i-1];
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        qzh[i]=qzh[i-1]^arr[i];
    }
    long long cnt=0,maxn=0;
    for(int l=1;l<=n;l++)
    {
        for(int i=l;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(qu(i,j)==k)
                {
                    cnt++;
                    i=j+1;

                }
            }
        }
        maxn=max(cnt,maxn);
        cnt=0;
    }

    cout<<maxn;
}
