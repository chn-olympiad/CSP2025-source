#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxx=INT_MIN,cnt,sum,x;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        x=0;
        for(int j=1;j<=n;j++)
        {
            x++;
            for(int t=x;t<=i;t++)
            {
                if(i==1) cnt=a[t];
                else cnt=cnt ^ a[t];
            }
            if(cnt==k) sum++;
            cnt=0;
        }
    }
    cout<<sum;
    return 0;
}
