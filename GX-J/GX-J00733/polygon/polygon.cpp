#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,sum=0;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++) cin>>b[i];
    for(int i=3;i<=a;i++)
    {
        int bi[i];
        for(int j=0;j<i;j++) bi[j]=j;
        while(bi[0]<=a-i)
        {
            int ans=0,k=0;
            for(int j=0;j<i;j++)
            {
                ans+=b[bi[j]];
                k=max(k,b[bi[j]]);
            }
            if(ans>2*k)
            {
                sum++;
                sum%=998244353;
            }
            bi[i-1]++;
            int wz=i-1;
            while(bi[wz]>=a-(i-1-wz))
            {
                if(wz==0)
                    break;
                bi[wz-1]++;
                wz--;
                for(int j=wz+1;j<i;j++)
                    bi[j]=bi[j-1]+1;
            }
        }
    }
    cout<<sum%998244353;
    return 0;
}
