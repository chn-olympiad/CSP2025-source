#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int x,int y){
    return x>y;
}
int x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            if(i%n==0){
                cout<<i/n<<" ";
                if((i/n)%2==1){
                    cout<<n;
                }else{
                    cout<<1;
                }
            }else{
                cout<<i/n+1<<" ";
                if((i/n+1)%2==1){
                    cout<<i%n;
                }else{
                    cout<<n-(i%n)+1;
                }
            }
        }
    }
    return 0;
}
