#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int f(int t,int sum,int maxt){
    if(t==n)
    {
        return sum>2*maxt;
    }
    return f(t+1,sum+a[t],max(maxt,a[t]))%998244353+f(t+1,sum,maxt)%998244353;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<f(0,0,0)%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
