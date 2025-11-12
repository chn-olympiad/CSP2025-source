#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int li[1000001]={};
    int cnt=0;
    for(int i=0;i<n;i++)cin>>li[i];
    if(k==0){
        for(int i=0;i<n;i++){
            if(li[i]==0)cnt++;
            else if(li[i]==li[i+1])cnt++,i++;
        }
    }else if(k==1){
        for(int i=0;i<n;i++){
            if(li[i]+li[i+1]==1)cnt++,i++;
        }
    }
    cout<<cnt;
    return 0;
}