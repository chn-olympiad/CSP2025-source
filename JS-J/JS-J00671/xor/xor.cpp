#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
       int sum=0,cnt=0;
       for(int i=1;i<=n;i++){
            if(a[i]==1){
                sum++;
                if(sum==2){
                    cnt++;
                    sum=0;
                }
            }
       }
       cout<<cnt;
       return 0;
    }
    else if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt++;
        }
        cout<<cnt;
        return 0;
    }
    return 0;
}
