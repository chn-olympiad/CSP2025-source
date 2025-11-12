#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxx=-1;long long sum=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int kebi=0;
        for(int j=1;j<=n;j++)
        {
            sum+=a[i];
            kebi++;
            if(a[j]>=maxx)
            {
                maxx=a[j];
                kebi++;
            }

            if(sum<maxx*2&&kebi>=3)
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
