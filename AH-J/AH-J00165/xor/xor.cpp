#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[500050],d[500050];
bool f[500050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    d[1]=a[1];
    for(int i=2;i<=n;i++){
        d[i]=a[i]+d[i-1];
    }
    int l=1;
    int r=1;
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                s++;
            }
        }
        cout<<s;
        return 0;
    }
    while(l<=n&&r<=n){
        while(a[l]==0){
            l++;
            r=l;
        }
        if(l==r){
            if(a[l]%k==0){
                s++;
                l++;
                r++;
            }else if(a[l]%k!=0){
                r++;
            }
        }else if(l!=r){
            if((d[r]-d[l]+a[l])%k==0){
                s++;
                l=r+1;
                r=l;
            }else if((d[r]-d[l]+a[l])%k!=0){
                r++;
            }
        }
    }
    cout<<s;
    return 0;
}
