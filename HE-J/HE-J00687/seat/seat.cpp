#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int b[1005];
int c[1005];
int d;
int sum=0;
int ans=0;
int shu=0;
int n,m;
int t=0,q=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    d=b[1];
    sort(b,b+(n*m)+1);
    for(int i=n*m;i>=1;i--){
        sum++;
        c[sum]=b[i];
    }
    for(int i=1;i<=m;i++){
            shu++;
            if(shu%2==0){
                q++;
            }
            if(shu%2==0){
                t=n*(q-1)+(n*shu/2);
                sort(c+1+t,c+n*m+1-(n*m-t-n));
            }
        for(int j=1;j<=n;j++){
            ans++;
            a[i][j]=c[ans];
            if(a[i][j]==d){
                cout<<i<<' '<<j;
            }
        }
    }
    return 0;
}
