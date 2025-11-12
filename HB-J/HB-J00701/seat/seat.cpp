#include <bits/stdc++.h>
using namespace std;
int n,m,s,a[102];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    int b=a[0],ans=0;
    sort(a,a+s,cmp);
    for(int i=0;i<s;i++){
        if(a[i]>b){
            ans++;
        }
    }
    int c=ans%n,d=ans/n;
    if(d%2==0){
        cout<<d+1<<" "<<c+1;
    }else{
        cout<<d+1<<" "<<n-c;
    }
    return 0;
}
