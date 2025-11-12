#include<bits/stdc++.h>
using namespace std;

long long a[500010],n,m,sum=0;
bool vis[1000010];

int main () {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            long long cnt=a[i],sum=0;
            bool sign=0
            for (int k=i+1;k<=j;k++) {
                if (vis[k]==0) cnt=cnt^a[k];
                else sign=1,break;
                vis[k]=1;
            }
            if (cnt==m&&sign==1) sum++;
        }
    }
    cout<<sum;
    return 0;
}
