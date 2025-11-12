#include<iostream>
#include<algorithm>
using namespace std;
int n,m,id[105],a[105],R,pos,h,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(R==a[i]){
            pos=n*m-i+1;
            break;
        }
    }
    //cout<<R<<' '<<pos<<endl;
    l=(pos+n-1)/n;
    h=(pos-1)%n+1;
    if(l%2==0){
        h=n-h+1;
    }
    cout<<l<<' '<<h<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
