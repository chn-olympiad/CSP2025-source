#include<bits/stdc++.h>
using namespace std;
long long s,x[1050000];
int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,ans=0;
    cin>>n>>k;
    long long head=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>s;
        head++;
        x[head]=s;
        for(long long j=1;j<head;j++)
        {
            x[j]^=s;
        }
        for(long long j=head;j>=1;j--)
        {
            if(x[j]==k)
            {
                ans++;
                head=0;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
