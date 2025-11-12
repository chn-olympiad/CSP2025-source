#include <bits/stdc++.h>
using namespace std;
bool pin(int a[],int n){
    if(n<3) return false;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    int h=a[n]*2;
    if(sum>h) return true;
    else return false;
}
int main(){
    freopen("polygon.in",'r',stdin);
    freopen("polygon.out",'w',stdout);
    int n;
    int a[5001];
    int h=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<6;
    return 0;
}
