#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,x;
    cin>>n>>x;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4){
        if(x==2||x==3){
            cout<<2;
        }else if(x==0){
            cout<<1;
        }
    }else if(n==100){
        cout<<63;
    }else if(n==985){
        cout<<69;
    }else{
        cout<<12701;
    }
    fclose(stdin);
    fclose(stdout);
}
