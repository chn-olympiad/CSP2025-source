#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long i,j,a[10005][3],t,n,e[10005],r[10005],k=0,c=0;
    cin>>t;
    for(int q=t;q>=0;q--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1]){
                e[i]=a[i][0];
            }
            else{
                e[i]=a[i][1];
            }
            if(e[i]>=a[i][2]){
                r[i]=e[i];
            }
            else{
                r[i]=a[i][2];
            }

        }
        for(int y=n;y>=0;y--){
            k=k+r[c];
            c++;
        }
    cout<<k<<endl;
    }
    return 0;
}
