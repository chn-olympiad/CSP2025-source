#include<bits/stdc++.h>
using namespace std;
int cmp(int n,int m){
    return n>m;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t1=0,p=0,pm=0;
    cin>>n>>m;
    int a[n*m+10];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    t1=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==t1){
            pm=i+1;
            p=pm/n;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                pm--;
                if(pm==0){
                    cout<<i<<" "<<j;
                }
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                pm--;
                if(pm==0){
                    cout<<i<<" "<<j;
                }
            }
        }
    }
    return 0;
}
