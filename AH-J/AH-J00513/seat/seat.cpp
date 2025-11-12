#include<bits/stdc++.h>
using namespace std;
long long n,m,xb=0,a[200],name;
string s;
long long slen;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    name=a[1];
    for(long long i=2;i<=n*m;i++){
            cin>>a[i];
    }
    sort(a+1,a+1+(n*m));
    xb=n*m;
    for(long long i=0;i<=m;){
        i++;
        for(long long j=1;j<=n;j++,xb--){
            if(a[xb]==name){
                cout<<i<<" "<<j;
                return 0;
            }
        }
        i++;
        for(long long j=n;j>=1;j--,xb--){
            if(a[xb]==name){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}


