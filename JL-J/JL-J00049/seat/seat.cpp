#include<bits/stdc++.h>
using namespace std;
int n,m,pos=1,biaoji;
const int N=1000;
bool cmp(int a,int b){
    return a>b;
}
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            biaoji=a[i];
        }
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[pos]==biaoji){
                cout<<i<<" "<<j;
                return 0;
            }
            pos++;
        }
        i++;
        for(int j=n;j>=1;j--){
            if(a[pos]==biaoji){
                cout<<i<<" "<<j;
                return 0;
            }
            pos++;
        }
    }
    return 0;
}
