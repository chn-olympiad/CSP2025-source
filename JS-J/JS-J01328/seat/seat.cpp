#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],flag,cnt=0,p=1,q=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++cnt];
            if(cnt==1){
                flag=a[1];
            }
        }
    }
    sort(a+1,a+cnt+1);
    reverse(a+1,a+cnt+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==flag){
            cout<<q<<" "<<p;
            break;
        }
        if(q%2){
            if(p==n){
                q++;
            }
            else{
                p++;
            }
        }
        else{
            if(p==1){
                q++;
            }
            else{
                p--;
            }
        }
    }
    return 0;
}
