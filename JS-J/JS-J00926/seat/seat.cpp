#include<bits/stdc++.h>
using namespace std;
long long b[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    long long a,r,cnt;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    r=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(b[i]==r){
            cnt=n*m-i+1;
            break;
        }
    }
    long long h,l;
    if(cnt%n==0) l=cnt/n;
    else l=cnt/n+1;
    if(cnt%n==0){
        if(l%2==0){
            h=1;
        }else{
            h=n;
        }
    }else{
        if(l%2!=0) h=cnt%n;
        else h=n-(cnt%n)+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
