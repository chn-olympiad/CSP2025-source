#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a[10000],b[10000][10000],ans;
bool cmp(int a,int b){
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    r=a[1];

    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(r==a[i])
        {
            r=i;
        }
    }
    while(r>n){
        r-=n;
        ans++;
    }
    ans++;
    if(ans%2==1){
        cout<<ans<<' '<<r%n;
    }else{
        cout<<ans<<' '<<r%n+1;
    }
    return 0;
}
