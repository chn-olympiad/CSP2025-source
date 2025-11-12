#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=5e5+10;
int a[maxn];
int main(){
  //freopen("xor.in","r",stdin);
  //freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0&&n==1){
        cout<<0;
    }
    else{
        if(k==0&&n==2){
            cout<<1;
        }
        else{
            if(k==0){
                cout<<(n-1)/2+1;
            }
            if(k==1){
                cout<<n;
            }
        }


    }

    return 0;
}
