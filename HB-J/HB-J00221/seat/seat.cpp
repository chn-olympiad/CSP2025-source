#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],k;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    k=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1,j=0;i<=n*m;i+=n,j=(j+1)%2){
        if(a[i+n-1]>k) continue;
        for(int f=0;f<n;f++){
            if(a[i+f]==k){
                if(j){
                    cout<<(i-1)/n+1<<" "<<n-f;
                    break;
                }
                else{
                    cout<<(i-1)/n+1<<" "<<f+1;
                    break;
                }
            }
        }
        break;
    }
    return 0;
}
