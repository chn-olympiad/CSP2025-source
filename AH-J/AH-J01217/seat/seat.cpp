#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+5;
int a[N],f[N];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        f[a[i]]=1;
    }
    int mi=0;
    for(int i=100;i>=0;i--){
        if(f[i]==1){
            if(i==a[1])break;
            else mi++;
        }
    }
    mi++;
    int ni=0;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                ni++;
                if(ni==mi){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }else{
            for(int j=m;j>=1;j--){
                ni++;
                if(ni==mi){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }

    }
return 0;
}
