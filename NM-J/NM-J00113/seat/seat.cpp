#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],p=0,q=0,ma,e=0,w=0,pd=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    ma=a[0];
    sort(a,a+n*m,cmp);
    while(pd==0){
        for(int i=0;i<n;i++){
            if(a[w]==ma){
                cout<<p+1<<" "<<i+1;
                pd=1;
                break;
            }
            w++;
        }
        if(pd==1) break;
        p++;
        for(int i=n-1;i>=0;i--){
            if(a[w]==ma){
                cout<<p+1<<" "<<i+1;
                pd=1;
                break;
            }
            w++;
        }
        p++;
    }
    return 0;
}
