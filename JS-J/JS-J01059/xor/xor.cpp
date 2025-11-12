#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1],ans=0,last=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            last=i;
            ans++;
        }
        else
        {
            long long sum=a[i];
            for(int j=i-1;j>last;j--)
            {
                sum=sum^a[j];
                if(sum==k)
                {
                    last=i;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
