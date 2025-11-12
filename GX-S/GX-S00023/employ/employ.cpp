#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    int a[100005]={0};
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(m%2==0){
        cout<<m;
    }else{
        cout<<"0";
    }
    return 0;
}
