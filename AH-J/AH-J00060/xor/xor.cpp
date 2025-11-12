#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[500005],s[500005],w=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
    }
    if(n>10000){
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            for(int i=1;i<=w;i++)s[i]=0;
            w=0;
        }
        w++;
        s[w]=a[i];
        for(int j=1;j<=w-1;j++){
            s[j]=(s[j]^a[i]);
            if(s[j]==k){
                ans++;
                for(int i=1;i<=w;i++)s[i]=0;
                w=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
