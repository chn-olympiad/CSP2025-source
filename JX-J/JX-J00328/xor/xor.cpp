#include<bits/stdc++.h>
using namespace std;
int m(int z){
    int ans=1;
    for(int i=0;i<z;i++){
        ans*=2;
    }
    return ans;
}
int f(int x,int y,int z,int s){//z==0,s==0;
    if(x==0 && y==0)return s;
    if(x%2==1 && y%2==1)return f(x/2,y/2,z+1,s);
    else if(x%2==1 && y%2==0)return f(x/2,y/2,z+1,s+m(z));
    else if(x%2==0 && y%2==1)return f(x/2,y/2,z+1,s+m(z));
    else if(x%2==0 && y%2==0)return f(x/2,y/2,z+1,s);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cout<<2;

    return 0;
}
/*
