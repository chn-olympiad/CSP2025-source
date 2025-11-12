#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,tt=0,c=0,r=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int t=a[0];
    sort(a,a+m*n);
    for(int i=n*m;i>0;i--){
        if(a[i]==t){
            tt=n*m-i;
        }
    }
    for(int i=0;i<=n;i++){
        if(tt-m>0){
            tt=tt-m;
            c++;
        }
    }
    c++;
    if(c%2==0){
        tt--;
        r=m-tt;
    }
    else{
        r=tt;
    }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}