#include<bits/stdc++.h>
using namespace std;
int a,arr[5005],num;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>arr[i];
        num+=arr[i];
    }
    sort(arr+1,arr+a+1,cmp);
    if(arr[1]*2<num) cout<<1;
    else cout<<0;
    return 0;
}
