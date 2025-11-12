#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int num[10000];
int ans=0;

void x(int n,int max_,int num_,int cnt){
    if(cnt>=3 && num_+num[n]>max_){
        ans++;
        for(int i=n-1;i>=1;i--){
            x(i,max_,num_+num[n],cnt+1);
        }
    }else {
        for(int i=n-1;i>=1;i--){
            x(i,max_,num_+num[n],cnt+1);
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    for(int i=n;i>=1;i--){
        x(i,num[i],0,1);
    }
    cout<<ans%998%244%353;
    return 0;
}
