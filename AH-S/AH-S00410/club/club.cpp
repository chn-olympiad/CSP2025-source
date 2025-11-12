#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long ans=0;
    int n;cin>>n;
    int a[n+1][4],a1[n+1],a2[n+1],f[n+1],
    sum1=0,sum2=0,sum3=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
            a1[i]=1;sum1++;
            if(a[2]>=a[3])a2[i]=2;
            else a2[i]=3;
        }
        else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
            a1[i]=2;sum2++;
            if(a[1]>=a[3])a2[i]=1;
            else a2[i]=3;
        }
        else {
            a1[i]=3;sum3++;
            if(a[1]>=a[2])a2[i]=1;
            else a2[i]=2;
        }
        f[i]=a[i][a1[i]]-a[i][a2[i]];
    }
    for(int i=1;i<=n;i++)ans+=a[i][a1[i]];

    if(sum1<=n/2&&sum2<=n/2&&sum3<=n){
        cout<<ans<<endl;
        return ;
    }

    int the,more;
    if(sum1>n/2)the=1,more=sum1-n/2;
    else if(sum2>n/2)the=2,more=sum2-n/2;
    else the=3,more=sum3-n/2;

    int ss[n+1]={0},s=0;

    for(int i=1;i<=n;i++){
        if(a1[i]==the){
            ss[++s]=f[i];
        }
    }
    int i=1;
    sort(ss+1,ss+s);
    while(more--){
        ans-=ss[i++];
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}



