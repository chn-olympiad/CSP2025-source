#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,p,cnt;
bool b[500005];
bool f(int l,int r){
    if(b[l])return 0;
    int s=a[l];
    for(int i=l+1;i<=r;i++){
        if(b[i])return 0;
        else{
            s=(s^a[i]);
        }
    }
    if(s==k)return 1;
    return 0;
}
void g(int l,int r){
    if(f(l,r)){
        for(int i=l;i<=r;i++)b[i]=1;
        cnt++;
        p-=(r-l+1);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    p=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=p;i++){
        for(int j=1;j<=n-i+1;j++){
            g(j,j+i-1);
        }
    }cout<<cnt;
    return 0;
}
