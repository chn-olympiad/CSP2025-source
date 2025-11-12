#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[290];
int cmp(int x,int y){
    return x>y;
};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a1=0;
    long long q=n*m;
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+q,cmp);
    for(int i=0;i<q;i++){
        if(a[i]==a1){
            a1=i+1;
        }
    }
    long long zw=0;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                zw++;
                if(zw==a1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                zw++;
                if(zw==a1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
