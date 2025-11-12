#include<bits/stdc++.h>
using namespace std;
long long s[222][222],n,m,a[1111],tot,aa;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    aa=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(long long j=1;j<=m;j++){
        for(long long i=1;i<=n;i++){
            if(j%2==0){
                s[n-i+1][j]=a[++tot];
            }
            else{
                s[i][j]=a[++tot];
            }
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(s[i][j]==aa){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
