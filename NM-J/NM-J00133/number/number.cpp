#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a="";
    int sz[1000001]={0},b=0,bj=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            sz[b]=char(a[i])-48;
            b++;
        }
    }
    sort(sz,sz+b);
    for(b-1;b>=0;b--){
        if(sz[b]==0 && bj==0){
                bj=1;
            }
        else{
            cout<<sz[b];
        }
        bj=1;
    }
    return 0;
}
