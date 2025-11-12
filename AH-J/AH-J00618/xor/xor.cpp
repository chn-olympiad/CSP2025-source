#include <bits/stdc++.h>
//rp++
using namespace std;

int n,m,s,sum,s2,s3,s4;
int a[3001010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >>m;
    for(int k=1; k<=n; k++)
    {
        cin >> a[k];
        sum+=a[k];
        if(a[k]==0)s2++;
    }
    if(sum==n&&m==0)cout << (sum/2);
    else if(sum<n&&m==0)cout << ((n-s2)/2+s2);
    else if(sum<n&&m==1)
    {
        for(int k=1;k<n;k++)
        {
            if(a[k]==-1)continue;
            if(a[k]+a[k+1]==1){s3++;a[k]=-1;a[k+1]=-1;}
        }
        for(int k=1;k<n;k++)
        {
            if(a[k]==a[k+1]&&a[k]!=-1)s3++;
        }
        cout <<s3;
    }
    else if(sum>n&&m==0)
    {
        for(int k=1;k<n;k++)
        {
            if(a[k]==a[k+1]||a[k]==0)s4++;
        }
        if(a[n]==0)s4++;
        cout <<s4;
    }
    else cout << 0;
    return 0;
}
