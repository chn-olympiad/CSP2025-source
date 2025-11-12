#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,sum=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    y=n*m;
    for(int i=1;i<=y;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+y+1);
    for(int i=y;i>=1;i--){
        if(a[i]==x){
           x=y-i+1;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                sum++;
                if(sum==x){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=1;j<=n;j++){
                sum++;
                if(sum==x){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
}

