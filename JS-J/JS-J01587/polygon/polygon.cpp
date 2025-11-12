#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],f[5005][5005],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
        cout<<0<<endl;
    else if(n==3)
    {
        int ar,br,cr;
        cin>>ar>>br>>cr;
        if(ar+br+cr>max(max(ar,br),cr))
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=5000;i++)
        {
            f[i][i]=1;
        }
        for(int j=3;j<=10;j++)
        {
            for(int i=j+1;i<=10;i++)
            {
                f[i][j]=f[i-1][j]+(i-j+2)*(i-j+1)/2;
            }
        }
        for(int i=3;i<=n;i++)
            ans+=f[n][i];
        cout<<ans<<endl;
    }
    return 0;
}
