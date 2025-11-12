#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1);
    int cnt=0;
    for(int i=n*m;i>=1;i--){
        cnt++;
        if(num==a[i]) num=cnt;
    }
    bool f=false;
    for(int i=0;i<=m;i++){
        if(!f){
             for(int j=1;j<=n;j++){
                if(i*n+j==num){
                    cout<<i+1<<" "<<j;
                    return 0;
                }
                f=true;
            }
        }
        i++;
        if(f){
            for(int j=n;j>=1;j--){
                if(i*n+(n-j+1)==num){
                    cout<<i+1<<" "<<j;
                    return 0;
                }
                f=false;
            }
        }

    }
    return 0;
}
