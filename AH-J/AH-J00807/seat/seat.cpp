#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,a[105],pos,s[15][15],cnt;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    pos=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                s[j][i]=a[cnt];
                if(a[cnt]==pos){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                cnt++;
                s[j][i]=a[cnt];
                if(a[cnt]==pos){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }

    return 0;
}
