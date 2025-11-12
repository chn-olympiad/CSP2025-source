#include <bits/stdc++.h>
using namespace std;

int n,s;
int a[5005];
int cnt(int t){
    int maxn=0;
    for(int i=1;i<=t;i++){
        maxn=max(maxn,a[i]);
    }
    return maxn*2;
}
int len(int x,int y){
    int sum=0;
    for(int i=x;i<=y;i++){
        sum+=a[i];
    }
    return sum;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(len(1,3)>cnt(3)){
        s++;
    }
    cout<<s;
    return 0;
}
