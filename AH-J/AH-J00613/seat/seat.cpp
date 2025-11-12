#include<bits/stdc++.h>
using namespace std;
int n,m,sb,ss[106];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>sb;
    ss[1]=sb;
    for(int i=2;i<=n*m;i++)
        cin>>ss[i];
    sort(ss+1,ss+n*m);

    int sum=n*m,ans=0;
    while(sum!=1){
        ans++;
        if(ss[sum--]==sb)break;
    }
    if(sum==1){
        cout<<m<<' '<<n;return 0;
    }

    int x=(ans-1)/n+1,y;
    if(x%2==1){
        y=ans%n;
        if(y==0) y=n;
    }

    else {
        y=n+1-ans%n;
        if(y==n+1)y=1;
    }
    cout<<x<<' '<<y;
    return 0;
}
