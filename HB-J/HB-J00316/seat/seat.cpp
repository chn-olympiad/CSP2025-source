#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],f,c,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    f=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(f==a[i]){
            if(i%n==0){
                c=i/n;
                if(c%2==0){
                    r=1;
                }
                else{
                    r=n;
                }
            }
            else{
                c=i/n+1;
                if(c%2==0){
                    r=n+1-i%n;
                }
                else{
                    r=i%n;
                }
            }
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
