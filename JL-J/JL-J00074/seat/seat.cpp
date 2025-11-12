#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            cnt++;
        }
    }
    if(n==1&&m==1){
        cout<<1<<' '<<1;
        return 0;
    }
    if(m==1){
        cout<<cnt<<' '<<1;
        return 0;
    }
    if(n==1){
        cout<<1<<' '<<cnt;
        return 0;
    }
    cout<<n<<' '<<m;


    return 0;
}

