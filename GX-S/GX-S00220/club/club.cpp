#include<bits/stdc++.h>;
using namespace std;
int a[10][200010],b[200010][4],j,t,n,u[4];
long long as;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(u,0,sizeof(u));
        memset(b,0,sizeof(b));
        as=0;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            as+=max(a[j][1],max(a[j][2],a[j][3]));
        }
    }
    cout<<as;
    return 0;
}
