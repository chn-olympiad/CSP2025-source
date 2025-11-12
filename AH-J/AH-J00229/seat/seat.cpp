#include<bits/stdc++.h>
using namespace std;
int n,m;
struct AK{
    int x,id;
}a[1005];
bool cmp(AK t,AK w){
    return t.x>w.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            int x=i;
            if(x%n==0){
                x/=n;
                if(x%2==1){
                    cout<<x<<" "<<n;
                }else{
                    cout<<x<<" "<<1;
                }
            }else{
                int y=x%n;
                x/=n;
                x++;
                if(x%2==1){
                    cout<<x<<" "<<y;
                }else{
                    cout<<x<<" "<<n-y+1;
                }
            }
            break;
        }
    }
    return 0;
}
