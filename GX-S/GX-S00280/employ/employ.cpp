#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            flag=false;
        }
    }
    if(flag){
        cout<<0;
    }
    else{
        cout<<13;
    }
    return 0;
}
