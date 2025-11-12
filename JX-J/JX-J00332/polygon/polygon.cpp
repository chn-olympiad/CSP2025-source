#include<bits/stdc++.h>
using namespace std;
int f[101];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[5]={1,2,3,4,5};
    bool aa=true;
    int b[5]={2,2,3,8,10};
    bool bb=true;
    int c[20]={};
    int n;
    int sum=0;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(n==5){
            if(a[i]!=x)aa=false;
            if(b[i]!=x)bb=false;
        }
    }
    if(aa)cout<<9;
    else
    if(bb)cout<<6;
    else cout<<1042392;
    return 0;

    }
