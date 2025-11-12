#include<bits/stdc++.h>
using namespace std;

int n,m,s,t,a[1010],ans[110][110],r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    cin>>n>>m;
    s=n*m;
    t=s;
    for(int i=1;i<=s;i++){
        cin>>a[i];
        if(i==1){
            r=a[i];
        }
    }

    sort(a+1,a+1+s);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i][j]=a[t];
            t--;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==r){
                if(i%2==0){
                    cout<<i<<' '<<j+m-1;
                }else{
                    cout<<i<<' '<<j;
                }
                return 0;
            }
        }
    }
    return 0;
}