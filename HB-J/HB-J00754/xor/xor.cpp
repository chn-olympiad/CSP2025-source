#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100000],b[100000],c[100000],d,e,f,ans;
void yh(int x,int n){
    int k=1,l=1;
    for(int i=1;x==1;i++){
        a[i]=x%2;
        x=x/2;
        d++;
    }
    for(int j=d;j>=1;j++){
        b[k]=a[j];
        k++;
    }
    for(int i=1;n==1;i++){
        a[i]=n%2;
        x=x/2;
        e++;
    }
    f=max(e,d);
    for(int j=e;j>=1;j++){
        c[l]=a[j];
        l++;
    }
    for(int i=1;i<=f;i++){
        if(b[i]==c[i]){
            b[i]==0;
        }
        else{
            b[i]=1;
        }
    }
    return;
}
void zh(int m){
    for(int i=1;i<=m;i++){
        if(b[i]==1){
            ans+=pow(2,i);
        }
    }
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    yh(n,m);
    zh(f);
    cout<<ans;
    return 0;
}
