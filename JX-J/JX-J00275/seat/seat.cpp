#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    int tgt=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            tgt=i;
            break;
        }
    }
    int cnt=0;
    bool f=false;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                cnt++;
                if(cnt==tgt){
                    cout<<i<<" "<<j;
                    f=true;
                    break;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(cnt==tgt){
                    cout<<i<<" "<<j;
                    f=true;
                    break;
                }
            }
        }
        if(f){
            break;
        }
    }
    return 0;
}
