#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    if(n<3){
        cout<<"0";
        return 0;
    }
    sort(a,a+n);
    if(cnt>2*a[2]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}

