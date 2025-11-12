#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+10];
    int f=0;
    cin>>f;
    a[1]=f;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int l=0;
////    cout<<f<<endl;
////    for(int i=1;i<=n*m;i++){
////        cout<<a[i]<<" ";
////    }cout<<endl;
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//             cout<<a[++l]<<" ";
//        }cout<<endl;
//    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(a[++l]==f) cout<<i<<" "<<j;
            }
        }else{
            for(int j=m;j>=1;j--){
                if(a[++l]==f) cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
