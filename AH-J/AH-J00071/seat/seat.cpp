#include<bits/stdc++.h>
using namespace std;
long long n,m,a[106],b[106],l,h,cnt2,cnt;
bool jj;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n*m+1);
    for(int i=n*m;i>=1;i--){
        cnt++;
        if(b[i]==a[1]){
            break;
        }
    }
    l=1;
    h=1;
    for(int i=1;i<=n*m;i++){
        cnt2++;
        if(cnt2==cnt){
            cout<<l<<" "<<h;
            return 0;
        }
        if(jj==0){
           h++;
        }
        else{
            h--;
        }
        if(h>n){
            jj=1;
            h--;
            l++;
        }
        else if(h<1){
            jj=0;
            h++;
            l++;
        }
    }
    return 0;
}
