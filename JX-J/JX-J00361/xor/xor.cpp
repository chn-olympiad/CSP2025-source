#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],qz[N];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qz[i]=qz[i-1]^a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int back=0;
        for(int j=i;j<=n;j++)
        {
            if(qz[j]^qz[i]==k)
            {
                back++;
                i=j-1;
            }
        }
        sum=max(back,sum);
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
