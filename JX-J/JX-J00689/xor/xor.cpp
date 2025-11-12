#include<bits/stdc++.h>
using namespace std;

string tentotwo(int ten){
    string two="";
    while(ten!=1){
        char s=(ten%2)+'0';
        two+=s;
        ten/=2;
    }
    two+='1';
    reverse(two.begin(),two.end());
    return two;
}
int yihuo(string x,string y){
    int w=max(x.size(),y.size());
    if(x.size()<w){
        reverse(x.begin(),x.end());
        for(int i=x.size();i<w;i++){
            x+="0";
        }
        reverse(x.begin(),x.end());
    }
    else if(y.size()<w){
        reverse(y.begin(),y.end());
        for(int i=y.size();i<w;i++){
            y+="0";
        }
        reverse(y.begin(),y.end());
    }
    int cnt=0;
    for(int i=0;i<w;i++){
        if(x[i]!=y[i]){
            cnt++;
        }
    }
    return cnt;
}
int a[1000010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    bool f=0,f1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=1;
        }

    }
    if(!f){
        if(k==1){
            cout<<n;
        }
        if(k==0){
            cout<<n%2;
        }
    }





    return 0;
}
