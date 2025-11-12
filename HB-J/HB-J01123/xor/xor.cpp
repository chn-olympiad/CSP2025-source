#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){flag=0;}
    }
    int cnt1=0,cnt0=0;
    if(flag!=0){
        cout<<"0";
    }
    else if(flag==0){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt0++;
                }
            }
            cout<<cnt0;
        }
        else if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt1++;
                }
            }
            cout<<cnt1;
        }
    }
    return 0;
}
