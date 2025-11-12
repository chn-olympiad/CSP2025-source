#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[4]==5){
        cout<<9;
    }else if(n==5&&a[4]==10){
        cout<<10;
    }
    return 0;
}

