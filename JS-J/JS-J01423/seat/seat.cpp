#include<bits/stdc++.h>
using namespace std;
int a[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int x=a[1],pos;
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x)pos=i;
    }
    int tmp=1;
    for(int j=1;j<=m;j++){
        if(j%2==0){
            for(int i=n;i>=1;i--){
                if(tmp==pos){
                    cout<<j<<" "<<i;
                    return 0;
                }
                tmp++;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(tmp==pos){
                    cout<<j<<" "<<i;
                    return 0;
                }
                tmp++;
            }
        }
    }
    return 0;
}
