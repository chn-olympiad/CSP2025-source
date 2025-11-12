#include<bits/stdc++.h>
using namespace std;
int a[5005];
int f[5005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //cout<<(1^2);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            if(sum==-1){
                sum=a[i];
            }else{
                sum=sum^a[i];
            }
            f[i]=1;
        }else{
            sum=-1;
        }
        if(sum==k){
            cnt++;
            sum=-1;
        }
    }
    cout<<cnt;
    return 0;
}/*
*/
