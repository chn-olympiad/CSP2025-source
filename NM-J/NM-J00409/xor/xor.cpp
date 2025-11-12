#include<bits/stdc++.h>
using namespace std;
int n,k,mansx=1,s[500010],a[30],b[30];
bool bs=false;
void funand(int c){
    if(bs){
        int i=1;
        while(c>0){
            if(c%2==0||b[i]==0)b[i]==0;
            else b[i]==1;
            c/=2;
            i++;
        }
    }
    else{
        int i=1;
        while(c>0){
            if(c%2==0||b[i]==0)b[i]==0;
            else b[i]==1;
            c/=2;
            i++;
        }
        bs=true;
    }
}
void funor(int c){
    int i=1;
    while(c>0){
        if(c%2==1||a[i]==1)a[i]==1;
        else a[i]==0;
        c/=2;
        i++;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        funand(s[i]);
        funor(s[i]);
    }
    cout<<mansx;
    return 0;
}
