#include<bits/stdc++.h>
using namespace std;
int r,c,r1,c1,a[110],cnt,n;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>r>>c;
    cnt=r*c;
    for(int i=1;i<=(r*c);i++)cin>>a[i];
    sort(a+2,a+(r*c)+1);
    for(int i=1;i<(r*c);i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
            cnt--;
        }
        else break;
    }
    if(cnt%r==0)n=cnt/r;
    else n=cnt/r+1;
    cout<<n<<' ';
    if(n%2==1){
        if(cnt%r!=0)cout<<cnt%r;
        else cout<<r;
    }
    else cout<<c-(cnt%r)+1;
    return 0;
}
