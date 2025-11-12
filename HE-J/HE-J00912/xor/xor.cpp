#include<bits/stdc++.h>
using namespace std;
const int maxn=500050;
int n,k,a[maxn],sum[maxn],cnt[505];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    int anss=0,las=n;
    memset(cnt,0,sizeof(cnt));
    for(int i=n;i>=0;i--)
    {
        int findk=k^sum[i];;
        if(cnt[findk])
        {
            anss++;
            for(int j=i+1;j<=las;j++) cnt[sum[j]]--;
            las=i;
        }
        cnt[sum[i]]++;
    }
    cout<<anss<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
