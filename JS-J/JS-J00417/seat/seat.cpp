#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,nm,a[1000],cnt;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    nm=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    cnt=n*m;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                if(a[cnt]==nm){
                    cout<<j<<" "<<i;
                    return 0;
                }else cnt--;
            }
        }else{
         for(int i=n;i>=1;i--){
                if(a[cnt]==nm){
                    cout<<j<<" "<<i;
                    return 0;
                }else cnt--;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

