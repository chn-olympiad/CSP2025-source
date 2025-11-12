#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    long long cnt=0;
    int n;
    int a[5005];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
        for(int j=1;j<=n-i+1;j++)
            {   
                int k=j+i-1;
                int max=0;
                int he=0;
                for(int p=j;p<=k;p++)
                {
                    cout<<a[p]<<" ";
                    if(a[p]>max) max=p;
                    he+=a[p];
                }
                cout<<endl;
                if(he>2*max) cnt++;
            }
    cnt%=998244353;
    cout<<cnt<<'\n';
    return 0;
}
