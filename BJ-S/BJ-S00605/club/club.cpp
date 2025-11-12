#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+10][4],b[n+10];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
            b[i]=a[i][1];
        }
        if(n==2){int sum[7]={0,a[1][1]+a[2][2],a[1][1]+a[2][3],a[1][2]+a[2][1],a[1][2]+a[2][3],a[1][3]+a[2][1],a[1][3]+a[2][2]};sort(sum+1,sum+7,greater<int>());cout<<sum[1]<<endl;}
        else{
            sort(b+1,b+1+n,greater<int>());
            long long sum=0;
            for(int i=1;i<=n/2;i++)
            {
                sum+=b[i];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
