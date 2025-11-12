#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++) cin>>a[i];
    int t=a[1];
    sort(a+1,a+k+1);
    reverse(a+1,a+k+1);
    int i=1,j=1,cnt=1;
    bool p=0;
    while(cnt<=k){
        if(a[cnt]==t){
            cout<<j<<' '<<i;
            return 0;
        }
        if(p==0) i++;
        else i--;
        if(i>n||i==0){
            p^=1;
            if(p) i--;
            else i++;
            j++;
        }
        cnt++;
    }
    return 0;
}
