#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
    }
    int t=x[1];
    sort(x+1,x+n*m+1);
    int a=0,b=1,cnt=0,flag=0;
    for(int i=n*m;i>=1;i--){
        cnt++;
        if(x[i]==t){
            if(flag==0){
                a=cnt;
            }
            else{
                a=n-cnt+1;
            }
            cout<<b<<" "<<a;
            break;
        }
        if(cnt==n){
            b++;
            cnt=0;
            if(flag==1){
                flag=0;
            }
            else{
                flag=1;
            }
        }
    }
}