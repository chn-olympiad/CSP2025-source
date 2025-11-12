#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[15][15];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1&&m==1) {
        cout<<"1 1";
        return 0;
    }
    long long r=a[1];
    long long cnt=1;
    sort(a+1,a+1+(n*m),cmp);
    if(r==a[1]){
        cout<<"1 1";
        return 0;
    }
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=a[cnt++];
            }

            j++;
        }
        if(j%2==0){
            for(int i=n;i>=1;i--){
                b[i][j]=a[cnt++];
            }

            j++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==r) {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
