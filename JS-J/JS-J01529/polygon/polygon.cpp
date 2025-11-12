#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,sum=0,cnt=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++)
    {
        sum=0;
        for(int j=i;j<=n;j++)
        {
            sum+=a[j];
            if(sum>=a[j]*2 && j-i>=2) cnt++;
        }
    }
    cnt=cnt*3/2;
    cout<<cnt%998%244%353;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
