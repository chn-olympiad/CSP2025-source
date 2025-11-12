#include<bits/stdc++.h>
using namespace std;
int t,n;
int ma = -1;
int u1=0,u2=0,s = 0;
struct abc{
    int a1,a2,a3;
}a[100010];
bool cmp(abc x,abc y){
    return abs(x.a1-x.a2)>abs(y.a1-y.a2);
}
int f[210][210][210];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }

        if (n>200){
            u1 = 0;
            u2 = 0;
            s = 0;
            sort(a+1,a+n+1,cmp);
            for (int i=1;i<=n;i++){
                if (u1==n/2){
                    s += a[i].a2;
                    u2++;
                }
                else if (u2==n/2){
                    s += a[i].a1;
                    u1++;
                }
                else if (a[i].a1>a[i].a2){
                    s += a[i].a1;
                    u1++;
                }
                else{
                    s += a[i].a2;
                    u2++;
                }
            }
            cout<<s<<endl;
            continue;
        }

        for (int i=0;i<=n/2;i++){
            for (int j=0;j<=n/2;j++){
                for (int k=0;k<=min(n/2,n-i-j);k++){
                    f[i][j][k] = 0;
                    if (i!=0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[i+j+k].a1);
                    if (j!=0) f[i][j][k] = max(f[i][j][k],f[i][j-1][k]+a[i+j+k].a2);
                    if (k!=0) f[i][j][k] = max(f[i][j][k],f[i][j][k-1]+a[i+j+k].a3);
                }
            }
        }

        for (int i=0;i<=n/2;i++){
            for (int j=(n/2-i);j<=n/2;j++){
                ma = max(ma,f[i][j][n-i-j]);
            }
        }
        cout<<ma<<endl;
        ma = -1;
    }
    return 0;
}
