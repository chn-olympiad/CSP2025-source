#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m,g[105],fg=0,fg_pos=0,cnt=0,isf=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cnt=n*m;
    for (int i=1;i<=n*m;i++){
        cin>>g[i];
    }
    fg=g[1];
    sort(g,g+n*m+1);
    for (int i=1;i<=n*m;i++){
        if (g[i]==fg)
            fg_pos=i;
    }
    for (int i=m;i>=1;i--){
        if (isf)
            break;
        if (i%2==1){
            for (int j=n;j>=1;j--){
                if (cnt==fg_pos){
                    cout<<j<<" "<<i;
                    isf=1;
                    break;
                }
                cnt--;

            }
        }
        else{
            for (int j=1;j<=n;j++){
                if (cnt==fg_pos){
                    cout<<j<<" "<<i;
                    isf=1;
                    break;
                }
                cnt--;
            }
        }
    }
    return 0;
}
