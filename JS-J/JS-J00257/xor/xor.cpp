#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n,k, ans=0;
    cin>>n>>k;
    
    vector<int> ther(n+1), qzh(n+1);
    vector<int8_t> used(n+1);
    for(int i=1; i<=n; i++) cin>>ther[i];
    qzh[1] = ther[1];
    for(int i=2; i<=n; i++) qzh[i] = qzh[i-1] ^ ther[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i+1; j++)
        {
            int kn = qzh[j] ^ qzh[i-1];
            if(kn == k)
            {
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
