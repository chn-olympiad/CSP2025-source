#include<bits/stdc++.h>
using namespace std;
const int maN=300;
int a[maN],n,m,len,malk,id;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++){
        cin>>a[i];
    }
    malk=a[1];
    sort(a+1,a+1+len,cmp);
    for(id=1;id<=len;id++){
        if(a[id]==malk){
            break;
        }
    }
 //   cout<<id<<endl;
    int cl=floor(1.0*id/n)+(id%n!=0),rw;
    if(cl&1){
        rw=id%n+n*(id%n==0);
    }else{
        rw=n-id%n+n*(id%n==0)+1;
    }
    cout<<cl<<' '<<rw;
//    for(int i=1;i<=len;i++)cout<<a[i]<<' ';cout<<endl;
//    cout<<a[upper_bound(a+1,a+1+n,malk)-a-1]<<' ';
//    cout<<a[lower_bound(a+1,a+1+n,malk)-a-1]<<' ';
}
