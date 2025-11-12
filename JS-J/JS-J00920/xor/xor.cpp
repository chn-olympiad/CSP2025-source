#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],ans=0;
bool flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
       // if(a[i]!=1){
       //     flag=1;
       // }
       // if(a[i]!=0){
     //       flag0=1;
       // }
       if(a[i]!=0&&a[i]!=1){
           flag=1;
       }
    }
    if(k==0){
        if(flag==0){
            ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                }
                else{
                    if(i<n){
                        if(a[i+1]==1){
                            ans++;
                            i++;
                        }
                    }
                }
            }
            cout<<ans;
            return 0;
        }
    }
    else if(k==1){
        if(flag==0){
            ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
                else{
                    if(i<n){
                        if(a[i+1]==0){
                            ans++;
                            i++;
                        }
                    }
                }
            }
            cout<<ans;
            return 0;
        }
    }
    cout<<0;
    return 0;
}

