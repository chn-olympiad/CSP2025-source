#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int h(int x,int y){
    int k=0,w=1;
    while(x||y){
        if(x%2!=y%2){
            k+=w;
            w*=2;
        }else{
            w*=2;
        }
        x/=2;
        y/=2;
    }
    return k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=h(s[i-1],a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(h(s[j],s[i-1])==k){
                cnt++;
                i=j+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
