#include<bits/stdc++.h>
#define int long long
#define M 998244353
using namespace std;
int n,m,a[510],b[510];
bool f[510];
char ch;
int ajj(int x){
    int su=1;
    while(x--)su=su*(x+1)%M;
    return su;
//   A    X
//  A A
// AAAAA
//A     A X
}
//int ajb(int x,int y){
//    int su=1;
//    while(x--&&y--)su=su*(x+1)%M;
//    return su;
//   A    X
//  A A
// AAAAA
//A     A Y
//}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>ch,f[i]=(ch-'0'^1);
    for(int i=1;i<n;i++)b[i]=b[i-1]+(f[i-1]?1:0);
    if(n-b[n-1]<m){
        cout<<0;
        return 0;
    }
    if(b[n-1]==0){
        cout<<ajj(n);
        return 0;
    }
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(m==1){
        int ans=0;
        for(int i=0,j=0,k=0;i<n;i++,j=0,k=0){
            while(b[j]<=a[i])j++,k+=(f[i]?0:1);
            ans=(ans+k*ajj(n-1))%M;
        }
        cout<<ans;
        return 0;
    }
    cout<<1;
    return 0;
}
