#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],q;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=2;i<=n*m;i++){
            q=a[1];
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==1){
        if(m==1){
            cout<<1<<" "<<1;
            return 0;
        }else{
            for(int i=1;i<=m*n;i++){
                if(q==a[i]){
                    cout<<1<<" "<<i;
                    return 0;
                }
            }
        }
    }else if(m==1){
        for(int i=1;i<=m*n;i++){
            if(q==a[i]){
                cout<<i<<" "<<1;
                return 0;
            }
        }
    }else if(n==2&&m==2){
        cout<<1<<" "<<2;
        return 0;
    }else {
        cout<<n<<" "<<m;
    }
    return 0;
}
