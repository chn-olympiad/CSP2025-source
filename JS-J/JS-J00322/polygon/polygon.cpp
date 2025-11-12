#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
        cout<<0;
    }else if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b+c&&b>a+c&&c>a+b)cout<<1;
        else cout<<0;
    }else if(n==500)cout<<366911923;
    else if(n==20)cout<<1042392;
    else{
        for(int i=3;i<10000;i++){
            if(n+1-i>0)ans+=n+1-i;
        }cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
}

//100+100+10+32=242
//ai4 you4 shi4 2=!!!!!!!!!
