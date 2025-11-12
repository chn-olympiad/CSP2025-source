#include <bits/stdc++.h>
using namespace std;
int n,t,a[5][100010],num[5],zhi;
long long ans;
bool pd1,pd2,pd3;
void dps(int zs,int m,long long k){
    num[zs]++;
    if(m!=n){
        if(pd1)
            if(num[1]*2<n)
                dps(1,m+1,k+a[1][m+1]);
        if(pd2)
            if(num[2]*2<n)
                dps(2,m+1,k+a[2][m+1]);
        if(pd3)
            if(num[3]*2<n)
                dps(3,m+1,k+a[3][m+1]);
    }else if(ans<k)ans=k;
    num[zs]--;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=pd1=pd2=pd3=zhi=0;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[1][i])pd1=1;
            if(a[2][i])pd2=1;
            if(a[3][i])pd3=1;
        }
        if(!pd2&&!pd3){
            sort(a[1]+1,a[1]+n+1,cmp);
            zhi=1;
        }

        else if(!pd1&&!pd3){
            sort(a[2]+1,a[2]+n+1,cmp);
            zhi=2;
        }

        else if(!pd1&&!pd2){
            sort(a[3]+1,a[3]+n+1,cmp);
            zhi=3;
        }
        if(zhi)
            for(int i=1;i*2<=n;i++)
                ans+=a[zhi][i];
        else
            dps(1,1,a[1][1]),dps(2,1,a[2][1]),dps(3,1,a[3][1]);
        cout<<ans<<'\n';
    }
    return 0;
}
