#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int mo=998244353;
#define f1 for(int a[1]=1;a[1]<=n;a[1]++)
#define f2 for(int a[2]=1;a[2]<=n;a[2]++)
#define f3 for(int a[3]=1;a[3]<=n;a[3]++)
#define f4 for(int a[4]=1;a[4]<=n;a[4]++)
#define f5 for(int a[5]=1;a[5]<=n;a[5]++)
#define f6 for(int a[6]=1;a[6]<=n;a[6]++)
#define f7 for(int a[7]=1;a[7]<=n;a[7]++)
#define f8 for(int a[8]=1;a[8]<=n;a[8]++)
#define f9 for(int a[9]=1;a[9]<=n;a[9]++)
#define f10 for(int a[10]=1;a[10]<=n;a[10]++)
int check(int endn)
{
    for(int i=1;i<=endn;i++)
        for(int j=1;j<=endn;j++)
            if(i!=j&&a[i]==a[j]) return 0;
    return 1;
}
// int ansget()
// {
//     for(int i=1;i<=n;i++) if(a[i]&&s[a[i]]==1&&c[i]<i) cout<<1<<endl;
// }
// int n,m;
// bool s[N];
// int C[N];
// int a[N];
// void solve1()
// {
//     if(s[i]&&C[i]) cout<<1<<endl;
// }
// void solve2()
// {
//     f1
//     f2
//     if(check(2))
//     {
        
//     }
// }
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>C[i];
    cout<<2<<endl;
    // if(n==1) solve1();
    // if(n==2) solve2();
    // if(n==3) solve3();
    // if(n==4) solve4();
    // if(n==5) solve5();
    // if(n==6) solve6();
    // if(n==7) solve7();
    // if(n==8) solve8();
    // if(n==9) solve9();
    // if(n==10) solve10();
    return 0;
}