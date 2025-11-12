#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],d,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                d++;
                if(a[d]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else for(int j=m;j>=1;j--){
            d++;
            if(a[d]==r){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
