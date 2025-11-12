#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
        return a >= b;
    }
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101];
    int s;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    s=a[0];
    sort(a,a+n*m,cmp);
    int ans=0;
    for(;ans<n*m;ans++){
        if(a[ans]==s){
            break;
        }
    }
    ++ans;
    int flag=0;
    int ma=ans/n+1,na=ans%n-1;
    if(ma%2==0){
        flag=1;
    }

    if(na==-1){
        cout<<ma-1<<" ";
        if(flag) cout<<n;
        else cout<<1;
        return 0;
    }
    cout<<ma<<" ";
    if(flag){
        cout<<n-na;
    }
    else cout<<++na;
    return 0;
}
