#include<bits/stdc++.h>
using namespace std;
long long n[32564],m[346654],s[3244321];
int main(){
    freopen("polygon.in",'r',stdin);
    freopen("polygon.out",'w',stdout);
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>n[i];
        m[i]+=n[i];
        s[i]=n[i]*2;
    }
    if(max(s[1],max(s[2],s[3]))>m[a]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
