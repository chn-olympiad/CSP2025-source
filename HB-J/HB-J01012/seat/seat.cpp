#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,m,a[110],b[12][12],c;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }c=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    long long p=1;
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            b[i][j]=a[p],p++;
        }
    }for(long long i=2;i<=m;i+=2){
        for(long long l=1,r=n;l<=r;l++,r--){
            swap(b[i][l],b[i][r]);
        }
    }for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(b[i][j]==c){
                cout<<i<<' '<<j;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
