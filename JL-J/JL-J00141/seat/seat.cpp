#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int data;
    int id;
}a[10005];

bool cmp(node x,node y){
    return x.data>y.data;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].data;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int idx=0;
    for(int j=1;j<=m;j++){
        if(j%2==0){
            for(int i=n;i>=1;i--){
                if(a[++idx].id!=1)continue;
                cout<<j<<" "<<i;
                return 0;
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[++idx].id!=1)continue;
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
