#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=0;
    cin>>x;
    a[1]=x;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m);
   // for(int i=1;i<=n*m;i++){
       // cout<<a[i]<<" ";
   // }
   // cout<<endl;
    bool flag=1;
    int num=n*m+1;
    for(int i=1;i<=m;i++){
        if(flag){
            for(int j=1;j<=n;j++){
                if(a[--num]==x){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
               // cout<<i<<" "<<j<<":"<<a[num]<<endl;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[--num]==x){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                //cout<<i<<" "<<j<<":"<<a[num]<<endl;
            }
        }
        flag=!flag;
    }
    return 0;
}


