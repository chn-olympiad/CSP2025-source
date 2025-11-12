#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],b[5010],k=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==0||n==1||n==2) cout<<0;
    else{
        if(2*a[1]<a[1]+a[2]+a[3]) cout<<1;
        else cout<<0;
    }
    return 0;
}
