#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n=0,k=0,cnt=0,L=1,R=1;
    bool flag=false;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)cin>>a[i];
    while(L<=n&&R<=n){
        for(long long j=R;j<=n;j++)
        {
            long long ans=a[L];
            for(long long k=L+1;k<=j;k++)ans=ans^a[k];
            if(L==j)
            {
                ans=a[L];
            }
            if(ans==k)
            {
                cnt++;
                L=j+1;
                R=L;
                flag=true;

                break;
            }
        }
        if(!flag)L++;
        else flag=false;
    }
    cout<<cnt;
    return 0;
}
