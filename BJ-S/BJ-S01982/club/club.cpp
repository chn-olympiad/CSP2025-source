#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,dp[N],b[4],s[N][4],ans;
struct nd{
    int x,y,z;
}a[N];
bool cmp(nd a,nd b){return a.x>b.x;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        ans=0;
        cin >>n;
        for(int i=1;i<=n;i++)
            cin >>a[i].x >>a[i].y >>a[i].z;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++) ans+=a[i].x;
        cout <<ans;
    }
    return 0;
}
