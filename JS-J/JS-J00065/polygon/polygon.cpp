#include<bits/stdc++.h>
using namespace std;
int n;
int re(int x){
    int ans=0;
    for(int i=3;i<=x;i++){
        int aans=1;
        for(int j=x;j>i;j--){
            aans=aans*j;
        }
        for(int j=x-i;j>=2;j--){
            aans=aans/j;
        }
        ans+=aans;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        cout<<"1";
    }else{
        cout<<re(n);
    }
    return 0;
}
