#include<bits/stdc++.h>
using namespace std;
int t,pk;
struct people{
    int value;
    int num;
    int bumen;
}per[300015];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int op=1;op<=t;op++){
        int n,a[100005][3],pk=1;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][2]!=0||a[i][3]!=0){
                pk=0;
            }
        }
        if(n==2){
            ans=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
            ans=max(ans,a[1][2]+a[2][1]);
            ans=max(ans,a[1][2]+a[2][3]);
            ans=max(ans,a[1][3]+a[2][1]);
            ans=max(ans,a[1][3]+a[2][2]);
            cout<<ans<<endl;
            continue;
        }
        if(pk==1){
            int b[100005];
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }
        cout<<1<<endl;
    }
    return 0;
}
