#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
struct in{
    int id;
    int val;

};
in a[N];
int n,m;
bool cmp(in x,in y){
    return x.val>y.val;
}
int ans1;
int ans2;
int ans3;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            ans1=i;
            break;
        }
    }
    ans2=ceil(1.0*ans1/n);
    ans3=ans1-(ans1/n)*n;
    if(ans2%2==1){
        cout<<ans2<<' ';
        if(ans3==0){
            cout<<n;
        }
        else{
            cout<<ans3;
        }
    }
    else{
       cout<<ans2<<' ';
       if(ans3==0){
            cout<<1;
       }
       else{
            cout<<n-ans3+1;
       }
    }
    return 0;
}
