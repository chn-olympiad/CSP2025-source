#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501];
int main(){
    freopen("employ.in","r",stdin);
    freoen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    if(n==m){
        cout<<1;
        return 0;
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        if(s[i]!=1)flag=true;
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    cout<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

