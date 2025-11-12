#include<bits/stdc++.h>
using namespace std;
int f[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int x;
    cin>>n>>m;
    int r;
    cin>>r;
    int sum=1;
    for(int i=0;i<(n*m)-1;i++){
        cin>>x;
        f[x]++;
    }
    for(int i=100;i>=0;i--){
        sum+=f[i];
        if(i==r){
            break;
        }
    }
    int h,l;
    l=sum/n+1;
    if(sum%n==0)l=sum/n;
    if(l%2==0){
        h=n-(sum%n)+1;
        if(sum%n==0)h=1;
    }
    if(l%2!=0){
        h=sum%n;
        if(h==0)h=n;
    }
    cout<<l<<" "<<h;
    return 0;
}
