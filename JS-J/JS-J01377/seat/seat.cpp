#include<bits/stdc++.h>
using namespace std;
struct _{
    int x;
    int y;
}a[101];
bool cmp(_ x,_ y){
    return x.x>y.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int i=0,tot=0;
    for(int j=1;j<=m;j++){
        if(j%2==0){
            while(i>1){
                i--;
                if(a[++tot].y==1){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
            i--;
        }else{
            while(i<n){
                i++;
                if(a[++tot].y==1){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
            i++;
        }
    }
    return 0;
}