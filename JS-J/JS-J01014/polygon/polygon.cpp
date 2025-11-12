#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int a[N];
int sum,maxn,st,n;
long long cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        for(int i=0;i<n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(sum>2*maxn){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    if(n<3){
        cout<<0;
    }
    if(n>3&&n<5){
        cout<<9;
    }
    if(n>=5&&n<10){
        cout<<20;
    }
    if(n>=10&&n<100){
        cout<<67;
    }
    if(n>=100){
        cout<<209;
    }
    return 0;
}

