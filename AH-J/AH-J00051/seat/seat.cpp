#include<bits/stdc++.h>
using namespace std;
long long a[15][15],n,m,r,s[125];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long len=n*m;
    for(long long i=1;i<=len;i++){
        cin>>s[i];
        if(i==1){
            r=s[i];
        }
    }
    sort(s+1,s+len+1);
    for(long long i=1;i<=m;i++){
        if(i%2==1){
            for(long long j=1;j<=n;j++){
                a[i][j]=s[len];
                len--;
            }
        }else{
            for(long long j=n;j>=1;j--){
                a[i][j]=s[len];
                len--;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            if(a[i][j]==r){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}

